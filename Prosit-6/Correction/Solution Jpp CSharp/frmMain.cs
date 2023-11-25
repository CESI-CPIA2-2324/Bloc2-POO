using PersonnesEtAdresses.Properties;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PersonnesEtAdresses
{
    public partial class frmMain : Form
    {

        private enum ModeEnum { Read, Insert, Update };

        private IList<Personne> _personnes;

        private int _personneIndex = -1;
        private int PersonneIndex
        {
            get
            {
                return _personneIndex;
            }
            set
            {
                if (value != _personneIndex)
                {
                    _personneIndex = value;
                    RefreshUI();
                }
            }
        }

        private int CurrentPersonId
        {
            get
            {
                if (_personneIndex < 0 || _personneIndex >= _personnes.Count)
                    return -1;
                return _personnes[_personneIndex].Id;
            }
        }

        private IList<Adresse> _adressesDeLaPersonne;

        private IList<Adresse> AdressesDeLaPersonne
        {
            get
            {
                return _adressesDeLaPersonne;
            }
            set
            {
                _adressesDeLaPersonne = value;
                bindingSource.DataSource = new ObservableCollection<Adresse>(_adressesDeLaPersonne);
            }
        }

        private ModeEnum _mode = ModeEnum.Read;

        private ModeEnum Mode
        {
            get { return _mode; }
            set
            {
                if (_mode == value)
                    return;
                _mode = value;
                RefreshUI();
            }
        }

        IRepository _repository;

        public frmMain()
        {
            InitializeComponent();
            dgvAdresses.DataSource = bindingSource;
            InitializeDB();
        }

        private void InitializeDB()
        {
            SQLAccess sqlAccess = new SQLAccess(Settings.Default.ConnectionString);
            _repository = new GestionPersonnes(sqlAccess);
            ReloadData();
        }

        private void ReloadData()
        {
            _personneIndex = -1;
            _personnes = _repository.GetPersonnes();
            Log($"{_personnes.Count} personnes trouvées.");
            PersonneIndex = 0; // ceci rappelera RafraichirUI();
        }

        public void RefreshUI()
        {
            switch (Mode)
            {
                case ModeEnum.Read:
                    if (_personnes.Count == 0)
                    {
                        txbId.Clear();
                        txbNom.Clear();
                        txbPrenom.Clear();
                        txbId.Clear();
                        AdressesDeLaPersonne = new List<Adresse>();
                    }
                    else
                    {
                        var personne = _personnes[_personneIndex];
                        txbId.Text = personne.Id.ToString();
                        txbNom.Text = personne.Nom;
                        txbPrenom.Text = personne.Prenom;
                        AdressesDeLaPersonne = _repository.GetAdresses(CurrentPersonId);
                        Log("Chargement de l'enregistrement : " + (PersonneIndex + 1));
                    }

                    break;
                case ModeEnum.Insert:
                    txbId.Clear();
                    txbNom.Clear();
                    txbPrenom.Clear();
                    txbId.Clear();
                    AdressesDeLaPersonne = new List<Adresse>();
                    break;
                case ModeEnum.Update:
                    break;
                default:
                    throw new Exception($"Note pour le développeur : Ce mode {Mode} n'est pas géré");
            }

            dgvAdresses.Columns["Id"].Visible = false;
            dgvAdresses.Columns["PersonneId"].Visible = false;

            bool modeWrite = (Mode == ModeEnum.Insert || Mode == ModeEnum.Update);
            btnSave.Enabled = modeWrite;
            btnCancel.Enabled = modeWrite;
            dgvAdresses.ReadOnly = !modeWrite;
            dgvAdresses.AllowUserToAddRows = modeWrite;
            txbNom.Enabled = modeWrite;
            txbPrenom.Enabled = modeWrite;

            btnFirst.Enabled = !modeWrite && _personnes.Count > 0 && PersonneIndex > 0;
            btnPrevious.Enabled = !modeWrite && _personnes.Count > 0 && PersonneIndex > 0;
            btnNext.Enabled = !modeWrite && _personnes.Count > 0 && PersonneIndex < _personnes.Count - 1;
            btnLast.Enabled = !modeWrite && _personnes.Count > 0 && PersonneIndex < _personnes.Count - 1;

            btnUpdate.Enabled = _personnes.Count > 0 && Mode == ModeEnum.Read;
            btnDelete.Enabled = _personnes.Count > 0 && Mode == ModeEnum.Read;
            btnNew.Enabled = Mode == ModeEnum.Read;
        }

        private void Log(string message)
        {
            txbMessage.Text += message + Environment.NewLine;
        }

        private void btnFirst_Click(object sender, EventArgs e)
        {
            if (_personnes.Count >= 0)
                PersonneIndex = 0;
        }

        private void btnPrevious_Click(object sender, EventArgs e)
        {
            if (PersonneIndex > 0)
                PersonneIndex--;
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if (PersonneIndex < _personnes.Count - 1)
                PersonneIndex++;
        }

        private void btnLast_Click(object sender, EventArgs e)
        {
            if (_personnes.Count >= 0)
                PersonneIndex = _personnes.Count - 1;
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            Mode = ModeEnum.Insert;
            Log("Veuillez saisir les renseignements avant d'enregister");
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txbNom.Text))
            {
                MessageBox.Show("Veuillez saisir un nom", "Erreur", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txbNom.Focus();
                return;
            }
            if (string.IsNullOrEmpty(txbPrenom.Text))
            {
                MessageBox.Show("Veuillez saisir un prénom", "Erreur", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txbNom.Focus();
                return;
            }
            switch (Mode)
            {
                case ModeEnum.Insert:
                    Personne newPersonne = new Personne();
                    newPersonne.Id = -1;
                    newPersonne.Nom = txbNom.Text;
                    newPersonne.Prenom = txbPrenom.Text;
                    _repository.Add(newPersonne, GetAdressesFromUI());
                    ReloadData();
                    PersonneIndex = _personnes.Count - 1;
                    break;
                case ModeEnum.Update:
                    Personne updatedPersonne = _personnes[_personneIndex];
                    updatedPersonne.Nom = txbNom.Text;
                    updatedPersonne.Prenom = txbPrenom.Text;
                    _repository.Update(updatedPersonne, GetAdressesFromUI());
                    break;
                default:
                    throw new Exception($"Note pour le développeur : Il ne doit pas être possible de cliquer sur le bouton enregistrer dans ce mode {Mode}");
            }
            Mode = ModeEnum.Read;
        }

        private IList<Adresse> GetAdressesFromUI()
        {
            BindingSource bindingSource = (BindingSource)dgvAdresses.DataSource;
            ObservableCollection<Adresse> observableCollection = (ObservableCollection<Adresse>)(bindingSource.DataSource);
            return observableCollection;
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            Mode = ModeEnum.Update;
            ReloadData();
            Log("Veuillez modifier les renseignements avant d'enregister");
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Etes vous sur de vouloir supprimer cette personne ?", "Confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes)
                return;

            int id = CurrentPersonId;
            if (id == -1)
                return;
            _repository.Delete(id);
            Log($"L'enregistrement a été supprimé (personne avec id = {id}) .");
            ReloadData();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Mode = ModeEnum.Read;
        }

        private void dgvAdresses_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            if (string.IsNullOrEmpty((string)(e.FormattedValue)))
            {
                MessageBox.Show("Le code postal et la ville sont des données obligatoires", "Erreur", MessageBoxButtons.OK, MessageBoxIcon.Error);
                e.Cancel = true;
            }
        }
    }
}
