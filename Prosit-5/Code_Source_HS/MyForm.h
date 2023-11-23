
//myForm.h
#pragma once

#include "CLserviceFichier.h"
#include "CLserviceImage.h"

namespace testWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;



	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btn_first;
	private: System::Windows::Forms::Button^  btn_previous;
	private: System::Windows::Forms::Button^  btn_next;
	private: System::Windows::Forms::Button^  btn_last;
	private: System::Windows::Forms::PictureBox^  pctBx;
	private: System::Windows::Forms::Label^  lbl_vision;
	private: System::Windows::Forms::Button^  btn_source;
	private: System::Windows::Forms::Button^  btn_destination;
	private: System::Windows::Forms::TextBox^  txt_source;
	private: System::Windows::Forms::TextBox^  txt_destination;

	private: System::Windows::Forms::GroupBox^  gpBox_typeProcessus;
	private: System::Windows::Forms::RadioButton^  rdb_effacer;
	private: System::Windows::Forms::RadioButton^  rdb_coiperEffacer;
	private: System::Windows::Forms::RadioButton^  rdb_copier;
	private: System::Windows::Forms::Button^  btn_proceder;
	private: System::Windows::Forms::TextBox^  txt_rslt;

	private: System::Windows::Forms::Label^  lbl_resultats;
	private: System::Windows::Forms::FolderBrowserDialog^  fld_source;
	private: System::Windows::Forms::FolderBrowserDialog^  fld_destination;
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: array<String^>^ listeDeFichier;
	private: NS_services::CLserviceImage ^ image;
	private: NS_services::CLserviceFichier^ svcFichier;
	private: int index;
	private: int nombreImages;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
			 /// le contenu de cette méthode avec l'éditeur de code.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->btn_first = (gcnew System::Windows::Forms::Button());
				 this->btn_previous = (gcnew System::Windows::Forms::Button());
				 this->btn_next = (gcnew System::Windows::Forms::Button());
				 this->btn_last = (gcnew System::Windows::Forms::Button());
				 this->pctBx = (gcnew System::Windows::Forms::PictureBox());
				 this->lbl_vision = (gcnew System::Windows::Forms::Label());
				 this->btn_source = (gcnew System::Windows::Forms::Button());
				 this->btn_destination = (gcnew System::Windows::Forms::Button());
				 this->txt_source = (gcnew System::Windows::Forms::TextBox());
				 this->txt_destination = (gcnew System::Windows::Forms::TextBox());
				 this->gpBox_typeProcessus = (gcnew System::Windows::Forms::GroupBox());
				 this->rdb_effacer = (gcnew System::Windows::Forms::RadioButton());
				 this->rdb_coiperEffacer = (gcnew System::Windows::Forms::RadioButton());
				 this->rdb_copier = (gcnew System::Windows::Forms::RadioButton());
				 this->btn_proceder = (gcnew System::Windows::Forms::Button());
				 this->txt_rslt = (gcnew System::Windows::Forms::TextBox());
				 this->lbl_resultats = (gcnew System::Windows::Forms::Label());
				 this->fld_source = (gcnew System::Windows::Forms::FolderBrowserDialog());
				 this->fld_destination = (gcnew System::Windows::Forms::FolderBrowserDialog());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBx))->BeginInit();
				 this->gpBox_typeProcessus->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // btn_first
				 // 
				 this->btn_first->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_first->Location = System::Drawing::Point(10, 337);
				 this->btn_first->Name = L"btn_first";
				 this->btn_first->Size = System::Drawing::Size(75, 23);
				 this->btn_first->TabIndex = 0;
				 this->btn_first->Text = L"<<";
				 this->btn_first->UseVisualStyleBackColor = true;
								 // 
				 // btn_previous
				 // 
				 this->btn_previous->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_previous->Location = System::Drawing::Point(91, 337);
				 this->btn_previous->Name = L"btn_previous";
				 this->btn_previous->Size = System::Drawing::Size(75, 23);
				 this->btn_previous->TabIndex = 1;
				 this->btn_previous->Text = L"<";
				 this->btn_previous->UseVisualStyleBackColor = true;
				 this->btn_previous->Click += gcnew System::EventHandler(this, &MyForm::btn_previous_Click);
				 // 
				 // btn_next
				 // 
				 this->btn_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_next->Location = System::Drawing::Point(172, 337);
				 this->btn_next->Name = L"btn_next";
				 this->btn_next->Size = System::Drawing::Size(75, 23);
				 this->btn_next->TabIndex = 2;
				 this->btn_next->Text = L">";
				 this->btn_next->UseVisualStyleBackColor = true;
				 this->btn_next->Click += gcnew System::EventHandler(this, &MyForm::btn_next_Click);
				 // 
				 // btn_last
				 // 
				 this->btn_last->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_last->Location = System::Drawing::Point(253, 337);
				 this->btn_last->Name = L"btn_last";
				 this->btn_last->Size = System::Drawing::Size(75, 23);
				 this->btn_last->TabIndex = 3;
				 this->btn_last->Text = L">>";
				 this->btn_last->UseVisualStyleBackColor = true;
				 this->btn_last->Click += gcnew System::EventHandler(this, &MyForm::btn_last_Click);
				 // 
				 // pctBx
				 // 
				 this->pctBx->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pctBx->Location = System::Drawing::Point(10, 27);
				 this->pctBx->Name = L"pctBx";
				 this->pctBx->Size = System::Drawing::Size(317, 302);
				 this->pctBx->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pctBx->TabIndex = 4;
				 this->pctBx->TabStop = false;
				 // 
				 // lbl_vision
				 // 
				 this->lbl_vision->AutoSize = true;
				 this->lbl_vision->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lbl_vision->Location = System::Drawing::Point(10, 8);
				 this->lbl_vision->Name = L"lbl_vision";
				 this->lbl_vision->Size = System::Drawing::Size(69, 13);
				 this->lbl_vision->TabIndex = 5;
				 this->lbl_vision->Text = L"Visionnage";
				 // 
				 // btn_source
				 // 
				 this->btn_source->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_source->Location = System::Drawing::Point(333, 27);
				 this->btn_source->Name = L"btn_source";
				 this->btn_source->Size = System::Drawing::Size(110, 20);
				 this->btn_source->TabIndex = 6;
				 this->btn_source->Text = L"Source";
				 this->btn_source->UseVisualStyleBackColor = true;
				 this->btn_source->Click += gcnew System::EventHandler(this, &MyForm::btn_source_Click);
				 // 
				 // btn_destination
				 // 
				 this->btn_destination->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_destination->Location = System::Drawing::Point(333, 53);
				 this->btn_destination->Name = L"btn_destination";
				 this->btn_destination->Size = System::Drawing::Size(110, 20);
				 this->btn_destination->TabIndex = 7;
				 this->btn_destination->Text = L"Destination";
				 this->btn_destination->UseVisualStyleBackColor = true;
				 this->btn_destination->Click += gcnew System::EventHandler(this, &MyForm::btn_destination_Click);
				 // 
				 // txt_source
				 // 
				 this->txt_source->Location = System::Drawing::Point(449, 27);
				 this->txt_source->Name = L"txt_source";
				 this->txt_source->ReadOnly = true;
				 this->txt_source->Size = System::Drawing::Size(307, 20);
				 this->txt_source->TabIndex = 8;
				 // 
				 // txt_destination
				 // 
				 this->txt_destination->Location = System::Drawing::Point(449, 53);
				 this->txt_destination->Name = L"txt_destination";
				 this->txt_destination->ReadOnly = true;
				 this->txt_destination->Size = System::Drawing::Size(307, 20);
				 this->txt_destination->TabIndex = 9;
				 // 
				 // gpBox_typeProcessus
				 // 
				 this->gpBox_typeProcessus->Controls->Add(this->rdb_effacer);
				 this->gpBox_typeProcessus->Controls->Add(this->rdb_coiperEffacer);
				 this->gpBox_typeProcessus->Controls->Add(this->rdb_copier);
				 this->gpBox_typeProcessus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->gpBox_typeProcessus->Location = System::Drawing::Point(336, 88);
				 this->gpBox_typeProcessus->Name = L"gpBox_typeProcessus";
				 this->gpBox_typeProcessus->Size = System::Drawing::Size(419, 44);
				 this->gpBox_typeProcessus->TabIndex = 10;
				 this->gpBox_typeProcessus->TabStop = false;
				 this->gpBox_typeProcessus->Text = L"Type de processus";
				 // 
				 // rdb_effacer
				 // 
				 this->rdb_effacer->AutoSize = true;
				 this->rdb_effacer->Location = System::Drawing::Point(357, 19);
				 this->rdb_effacer->Name = L"rdb_effacer";
				 this->rdb_effacer->Size = System::Drawing::Size(66, 17);
				 this->rdb_effacer->TabIndex = 2;
				 this->rdb_effacer->TabStop = true;
				 this->rdb_effacer->Text = L"Effacer";
				 this->rdb_effacer->UseVisualStyleBackColor = true;
				 // 
				 // rdb_coiperEffacer
				 // 
				 this->rdb_coiperEffacer->AutoSize = true;
				 this->rdb_coiperEffacer->Location = System::Drawing::Point(204, 19);
				 this->rdb_coiperEffacer->Name = L"rdb_coiperEffacer";
				 this->rdb_coiperEffacer->Size = System::Drawing::Size(120, 17);
				 this->rdb_coiperEffacer->TabIndex = 1;
				 this->rdb_coiperEffacer->TabStop = true;
				 this->rdb_coiperEffacer->Text = L"Copier et effacer";
				 this->rdb_coiperEffacer->UseVisualStyleBackColor = true;
				 // 
				 // rdb_copier
				 // 
				 this->rdb_copier->AutoSize = true;
				 this->rdb_copier->Location = System::Drawing::Point(113, 19);
				 this->rdb_copier->Name = L"rdb_copier";
				 this->rdb_copier->Size = System::Drawing::Size(61, 17);
				 this->rdb_copier->TabIndex = 0;
				 this->rdb_copier->TabStop = true;
				 this->rdb_copier->Text = L"Copier";
				 this->rdb_copier->UseVisualStyleBackColor = true;
				 // 
				 // btn_proceder
				 // 
				 this->btn_proceder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btn_proceder->ForeColor = System::Drawing::Color::Blue;
				 this->btn_proceder->Location = System::Drawing::Point(336, 141);
				 this->btn_proceder->Name = L"btn_proceder";
				 this->btn_proceder->Size = System::Drawing::Size(420, 61);
				 this->btn_proceder->TabIndex = 11;
				 this->btn_proceder->Text = L"Procéder";
				 this->btn_proceder->UseVisualStyleBackColor = true;
				 this->btn_proceder->Click += gcnew System::EventHandler(this, &MyForm::btn_proceder_Click);
				 // 
				 // txt_rslt
				 // 
				 this->txt_rslt->Location = System::Drawing::Point(337, 227);
				 this->txt_rslt->Multiline = true;
				 this->txt_rslt->Name = L"txt_rslt";
				 this->txt_rslt->ReadOnly = true;
				 this->txt_rslt->Size = System::Drawing::Size(419, 133);
				 this->txt_rslt->TabIndex = 12;
				 // 
				 // lbl_resultats
				 // 
				 this->lbl_resultats->AutoSize = true;
				 this->lbl_resultats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lbl_resultats->Location = System::Drawing::Point(334, 211);
				 this->lbl_resultats->Name = L"lbl_resultats";
				 this->lbl_resultats->Size = System::Drawing::Size(60, 13);
				 this->lbl_resultats->TabIndex = 13;
				 this->lbl_resultats->Text = L"Résultats";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(766, 373);
				 this->Controls->Add(this->lbl_resultats);
				 this->Controls->Add(this->txt_rslt);
				 this->Controls->Add(this->btn_proceder);
				 this->Controls->Add(this->gpBox_typeProcessus);
				 this->Controls->Add(this->txt_destination);
				 this->Controls->Add(this->txt_source);
				 this->Controls->Add(this->btn_destination);
				 this->Controls->Add(this->btn_source);
				 this->Controls->Add(this->lbl_vision);
				 this->Controls->Add(this->pctBx);
				 this->Controls->Add(this->btn_last);
				 this->Controls->Add(this->btn_next);
				 this->Controls->Add(this->btn_previous);
				 this->Controls->Add(this->btn_first);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->MaximizeBox = false;
				 this->Name = L"MyForm";
				 this->Text = L"[EI] [A2 MININF] Bloc Programmation orientée objet- Prosit 5";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBx))->EndInit();
				 this->gpBox_typeProcessus->ResumeLayout(false);
				 this->gpBox_typeProcessus->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		this->index = 0;
		this->nombreImages = 0;
	}

	private: System::Void btn_source_Click
	{
		int i;

		
		this->image = gcnew NS_services::CLserviceImage();

		this->fld_source->ShowDialog();
		this->txt_source->Text = this->fld_source->SelectedPath;

		this->listeDeFichier = this->svcFichier->explorer(this->txt_source->Text);


		for (i = 0; i < this->listeDeFichier->Length; i++)
		{
			this->txt_rslt->Text += this->listeDeFichier[i] + "\r\n";
		}
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}
	private: System::Void btn_destination_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->fld_destination->ShowDialog();
		this->txt_destination->Text = this->fld_destination->SelectedPath;
	}
	private: System::Void btn_first_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->index = 0;
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}
	private: System::Void btn_proceder_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		if (this->rdb_copier->Checked == true)
		{
			this->svcFichier->copier(this->listeDeFichier, this->txt_destination->Text);
			this->txt_rslt->Clear();
			this->txt_rslt->Text = "Les fichiers ont été copier dans le dossier : " + this->txt_destination->Text;
		}
		else if (this->rdb_coiperEffacer->Checked == true)
		{
			this->svcFichier->copierEffacer (this->listeDeFichier, this->txt_destination->Text);
			this->txt_rslt->Text = "Les fichiers ont été copier dans le dossier : " + this->txt_destination->Text;
		}
		
	}
	private: System::Void btn_next_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->index < this->listeDeFichier->Length - 1)
		{
			this->index++;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}
	private: System::Void btn_previous_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->index > 0)
		{
			this->index--;
			this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
		}
	}
	private: System::Void btn_last_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->index = this->listeDeFichier->Length - 1;
		this->pctBx->Image = image->lireImage(this->listeDeFichier[this->index]);
	}
	};
}