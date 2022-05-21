#pragma once
#include<cmath>
namespace CalculatorCR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::ComboBox^ comboBox1;












	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
	private: System::Windows::Forms::Label^ ћес€ц;









	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->ћес€ц = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(115, 162);
			this->button1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"–ассчитать ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(302, 252);
			this->textBox3->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(217, 22);
			this->textBox3->TabIndex = 3;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->numericUpDown2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown2->DecimalPlaces = 1;
			this->numericUpDown2->Location = System::Drawing::Point(10, 50);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(220, 25);
			this->numericUpDown2->TabIndex = 5;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(238, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(30, 30);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(239, 50);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(30, 30);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->numericUpDown3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown3->Location = System::Drawing::Point(10, 96);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 242, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(220, 25);
			this->numericUpDown3->TabIndex = 8;
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown3_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(236, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"—рок выплаты (ћес€цев)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(143, 252);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"≈жемес€чный платеж";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(214, 340);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"ѕереплата";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(302, 300);
			this->textBox1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(217, 22);
			this->textBox1->TabIndex = 12;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(302, 340);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(217, 22);
			this->textBox2->TabIndex = 13;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(143, 300);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"ќбща€ сумма выплат";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"јннуитетный платеж", L"ƒифференцированный платеж" });
			this->comboBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"јннуитетный платеж", L"ƒифференцированный платеж" });
			this->comboBox1->Location = System::Drawing::Point(315, 0);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(220, 25);
			this->comboBox1->TabIndex = 16;
			this->comboBox1->Text = L"јннуитетный платеж";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox1_KeyPress);
			// 
			// button14
			// 
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button14->Location = System::Drawing::Point(324, 162);
			this->button14->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(138, 39);
			this->button14->TabIndex = 29;
			this->button14->Text = L"—брос";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Location = System::Drawing::Point(9, 5);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999999, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(220, 25);
			this->numericUpDown1->TabIndex = 30;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged_1);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(302, 387);
			this->textBox4->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(217, 22);
			this->textBox4->TabIndex = 31;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged_1);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->numericUpDown4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown4->Location = System::Drawing::Point(525, 384);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 242, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(58, 25);
			this->numericUpDown4->TabIndex = 32;
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown4_ValueChanged_1);
			// 
			// ћес€ц
			// 
			this->ћес€ц->AutoSize = true;
			this->ћес€ц->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ћес€ц->Location = System::Drawing::Point(240, 390);
			this->ћес€ц->Name = L"ћес€ц";
			this->ћес€ц->Size = System::Drawing::Size(53, 19);
			this->ћес€ц->TabIndex = 33;
			this->ћес€ц->Text = L"ћес€ц";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(584, 461);
			this->Controls->Add(this->ћес€ц);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->MaximumSize = System::Drawing::Size(600, 500);
			this->MinimumSize = System::Drawing::Size(600, 500);
			this->Name = L"MyForm";
			this->Text = L" алькул€тор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double Roubles, Interest, Months, Calculate, Reset, FormulaAN_em, FormulaDP_em, overpay, sum, z, x, c, Stockholm = Months, Ghoul, InBoss1k;
		Roubles = System::Convert::ToDouble(numericUpDown1->Value);
		Interest = System::Convert::ToDouble(numericUpDown2->Value);
		Months = System::Convert::ToDouble(numericUpDown3->Value);
		Stockholm = System::Convert::ToDouble(numericUpDown4->Value);


		if (comboBox1->Text == "јннуитетный платеж")
		{
			z = Interest / 12 / 100;
			FormulaAN_em = z * pow((1 + z), Months) / (pow((1 + z), Months) - 1);
			x = FormulaAN_em * Roubles;
			textBox3->Text = "" + x;
			textBox3->Text = Convert::ToString(Math::Round(x, 2));
			sum = Roubles * FormulaAN_em * Months;
			textBox1->Text = "" + sum;
			textBox1->Text = Convert::ToString(Math::Round(sum, 2));
			overpay = ((sum - Roubles) * 100) / 100;
			textBox2->Text = "" + overpay;
			textBox2->Text = Convert::ToString(Math::Round(overpay, 2));
			if ((numericUpDown4->Value == 0) || (numericUpDown4->Value > numericUpDown3->Value))
			{
				textBox4->Text = "" + Months;
				textBox4->Text = Convert::ToString(Math::Round(Ghoul, 2));
			}
			else
			{
				textBox4->Text = "" + x;
				textBox4->Text = Convert::ToString(Math::Round(x, 2));

			}


		}
		else if (comboBox1->Text == "ƒифференцированный платеж")
		{
			z = Interest / 12 / 100;
			FormulaDP_em = (Roubles / Months) + (Roubles * (Interest / 100) / Months);
			FormulaAN_em = z * pow((1 + z), Months) / (pow((1 + z), Months) - 1);
			textBox3->Text = "" + FormulaDP_em;
			textBox3->Text = Convert::ToString(Math::Round(FormulaDP_em, 2));
			sum = Roubles * FormulaAN_em * Months;
			textBox1->Text = "" + sum;
			textBox1->Text = Convert::ToString(Math::Round(sum, 2));
			overpay = ((sum - Roubles) * 100) / 100;
			textBox2->Text = "" + overpay;
			textBox2->Text = Convert::ToString(Math::Round(overpay, 2));
			if ((numericUpDown4->Value == 0) || (numericUpDown4->Value > numericUpDown3->Value))
			{
				textBox4->Text = "" + Months;
				textBox4->Text = Convert::ToString(Math::Round(Ghoul, 2));
			}
			else if (numericUpDown4->Value == 1)
			{
				Ghoul = FormulaDP_em;
				textBox4->Text = "" + Ghoul;
				textBox4->Text = Convert::ToString(Math::Round(Ghoul, 2));
			}
			else
			{
				InBoss1k = (FormulaDP_em * Interest * Stockholm) / 365;
				Ghoul = FormulaDP_em - InBoss1k;
				textBox4->Text = "" + Ghoul;
				textBox4->Text = Convert::ToString(Math::Round(Ghoul, 2));
			}
		}
	}


	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		numericUpDown1->Value = 0;
		numericUpDown2->Value = 0;
		numericUpDown3->Value = 0;
		numericUpDown4->Value = 0;


	}
	private: System::Void numericUpDown1_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		e->Handled = true;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numericUpDown4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numericUpDown4_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
