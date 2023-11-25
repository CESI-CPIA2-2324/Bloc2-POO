
namespace PersonnesEtAdresses
{
    partial class frmMain
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btnFirst = new System.Windows.Forms.Button();
            this.lblId = new System.Windows.Forms.Label();
            this.txbMessage = new System.Windows.Forms.TextBox();
            this.dgvAdresses = new System.Windows.Forms.DataGridView();
            this.lblPrenom = new System.Windows.Forms.Label();
            this.lblNom = new System.Windows.Forms.Label();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnNew = new System.Windows.Forms.Button();
            this.btnLast = new System.Windows.Forms.Button();
            this.btnNext = new System.Windows.Forms.Button();
            this.btnPrevious = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.txbPrenom = new System.Windows.Forms.TextBox();
            this.txbNom = new System.Windows.Forms.TextBox();
            this.txbId = new System.Windows.Forms.TextBox();
            this.lblMessage = new System.Windows.Forms.Label();
            this.lblAdresses = new System.Windows.Forms.Label();
            this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.btnCancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAdresses)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // btnFirst
            // 
            this.btnFirst.Location = new System.Drawing.Point(34, 248);
            this.btnFirst.Name = "btnFirst";
            this.btnFirst.Size = new System.Drawing.Size(60, 34);
            this.btnFirst.TabIndex = 3;
            this.btnFirst.Text = "<<";
            this.btnFirst.UseVisualStyleBackColor = true;
            this.btnFirst.Click += new System.EventHandler(this.btnFirst_Click);
            // 
            // lblId
            // 
            this.lblId.AutoSize = true;
            this.lblId.Location = new System.Drawing.Point(34, 9);
            this.lblId.Name = "lblId";
            this.lblId.Size = new System.Drawing.Size(28, 25);
            this.lblId.TabIndex = 1;
            this.lblId.Text = "Id";
            // 
            // txbMessage
            // 
            this.txbMessage.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbMessage.Location = new System.Drawing.Point(34, 448);
            this.txbMessage.Multiline = true;
            this.txbMessage.Name = "txbMessage";
            this.txbMessage.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbMessage.Size = new System.Drawing.Size(822, 571);
            this.txbMessage.TabIndex = 2;
            this.txbMessage.TabStop = false;
            // 
            // dgvAdresses
            // 
            this.dgvAdresses.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvAdresses.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAdresses.Location = new System.Drawing.Point(318, 37);
            this.dgvAdresses.Name = "dgvAdresses";
            this.dgvAdresses.RowHeadersWidth = 62;
            this.dgvAdresses.RowTemplate.Height = 33;
            this.dgvAdresses.Size = new System.Drawing.Size(538, 365);
            this.dgvAdresses.TabIndex = 12;
            this.dgvAdresses.CellValidating += new System.Windows.Forms.DataGridViewCellValidatingEventHandler(this.dgvAdresses_CellValidating);
            // 
            // lblPrenom
            // 
            this.lblPrenom.AutoSize = true;
            this.lblPrenom.Location = new System.Drawing.Point(34, 168);
            this.lblPrenom.Name = "lblPrenom";
            this.lblPrenom.Size = new System.Drawing.Size(74, 25);
            this.lblPrenom.TabIndex = 4;
            this.lblPrenom.Text = "Prénom";
            // 
            // lblNom
            // 
            this.lblNom.AutoSize = true;
            this.lblNom.Location = new System.Drawing.Point(34, 85);
            this.lblNom.Name = "lblNom";
            this.lblNom.Size = new System.Drawing.Size(52, 25);
            this.lblNom.TabIndex = 5;
            this.lblNom.Text = "Nom";
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(34, 368);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(126, 34);
            this.btnDelete.TabIndex = 10;
            this.btnDelete.Text = "&Supprimer";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(34, 328);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(126, 34);
            this.btnUpdate.TabIndex = 8;
            this.btnUpdate.Text = "&Mise à jour";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnNew
            // 
            this.btnNew.Location = new System.Drawing.Point(34, 288);
            this.btnNew.Name = "btnNew";
            this.btnNew.Size = new System.Drawing.Size(126, 34);
            this.btnNew.TabIndex = 7;
            this.btnNew.Text = "&Nouveau";
            this.btnNew.UseVisualStyleBackColor = true;
            this.btnNew.Click += new System.EventHandler(this.btnNew_Click);
            // 
            // btnLast
            // 
            this.btnLast.Location = new System.Drawing.Point(232, 246);
            this.btnLast.Name = "btnLast";
            this.btnLast.Size = new System.Drawing.Size(60, 34);
            this.btnLast.TabIndex = 6;
            this.btnLast.Text = ">>";
            this.btnLast.UseVisualStyleBackColor = true;
            this.btnLast.Click += new System.EventHandler(this.btnLast_Click);
            // 
            // btnNext
            // 
            this.btnNext.Location = new System.Drawing.Point(166, 248);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(60, 34);
            this.btnNext.TabIndex = 5;
            this.btnNext.Text = ">";
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // btnPrevious
            // 
            this.btnPrevious.Location = new System.Drawing.Point(100, 248);
            this.btnPrevious.Name = "btnPrevious";
            this.btnPrevious.Size = new System.Drawing.Size(60, 34);
            this.btnPrevious.TabIndex = 4;
            this.btnPrevious.Text = "<";
            this.btnPrevious.UseVisualStyleBackColor = true;
            this.btnPrevious.Click += new System.EventHandler(this.btnPrevious_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(166, 288);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(126, 74);
            this.btnSave.TabIndex = 9;
            this.btnSave.Text = "&Enregistrer";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // txbPrenom
            // 
            this.txbPrenom.Location = new System.Drawing.Point(34, 196);
            this.txbPrenom.Name = "txbPrenom";
            this.txbPrenom.Size = new System.Drawing.Size(258, 31);
            this.txbPrenom.TabIndex = 2;
            // 
            // txbNom
            // 
            this.txbNom.Location = new System.Drawing.Point(34, 113);
            this.txbNom.Name = "txbNom";
            this.txbNom.Size = new System.Drawing.Size(258, 31);
            this.txbNom.TabIndex = 1;
            // 
            // txbId
            // 
            this.txbId.Location = new System.Drawing.Point(34, 37);
            this.txbId.Name = "txbId";
            this.txbId.ReadOnly = true;
            this.txbId.Size = new System.Drawing.Size(258, 31);
            this.txbId.TabIndex = 0;
            this.txbId.TabStop = false;
            // 
            // lblMessage
            // 
            this.lblMessage.AutoSize = true;
            this.lblMessage.Location = new System.Drawing.Point(34, 420);
            this.lblMessage.Name = "lblMessage";
            this.lblMessage.Size = new System.Drawing.Size(82, 25);
            this.lblMessage.TabIndex = 17;
            this.lblMessage.Text = "Message";
            // 
            // lblAdresses
            // 
            this.lblAdresses.AutoSize = true;
            this.lblAdresses.Location = new System.Drawing.Point(318, 9);
            this.lblAdresses.Name = "lblAdresses";
            this.lblAdresses.Size = new System.Drawing.Size(83, 25);
            this.lblAdresses.TabIndex = 18;
            this.lblAdresses.Text = "Adresses";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(166, 368);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(126, 34);
            this.btnCancel.TabIndex = 11;
            this.btnCancel.Text = "&Annuler";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(912, 1047);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.lblAdresses);
            this.Controls.Add(this.lblMessage);
            this.Controls.Add(this.txbId);
            this.Controls.Add(this.txbNom);
            this.Controls.Add(this.txbPrenom);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnPrevious);
            this.Controls.Add(this.btnNext);
            this.Controls.Add(this.btnLast);
            this.Controls.Add(this.btnNew);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.lblNom);
            this.Controls.Add(this.lblPrenom);
            this.Controls.Add(this.dgvAdresses);
            this.Controls.Add(this.txbMessage);
            this.Controls.Add(this.lblId);
            this.Controls.Add(this.btnFirst);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "frmMain";
            this.Text = "Personnes & Adresses";
            ((System.ComponentModel.ISupportInitialize)(this.dgvAdresses)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnFirst;
        private System.Windows.Forms.Label lblId;
        private System.Windows.Forms.TextBox txbMessage;
        private System.Windows.Forms.DataGridView dgvAdresses;
        private System.Windows.Forms.Label lblPrenom;
        private System.Windows.Forms.Label lblNom;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnNew;
        private System.Windows.Forms.Button btnLast;
        private System.Windows.Forms.Button btnNext;
        private System.Windows.Forms.Button btnPrevious;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.TextBox txbPrenom;
        private System.Windows.Forms.TextBox txbNom;
        private System.Windows.Forms.TextBox txbId;
        private System.Windows.Forms.Label lblMessage;
        private System.Windows.Forms.Label lblAdresses;
        private System.Windows.Forms.BindingSource bindingSource;
        private System.Windows.Forms.Button btnCancel;
    }
}

