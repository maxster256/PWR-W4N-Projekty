﻿namespace widowappIG
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.button14 = new System.Windows.Forms.Button();
            this.button15 = new System.Windows.Forms.Button();
            this.button16 = new System.Windows.Forms.Button();
            this.button17 = new System.Windows.Forms.Button();
            this.button18 = new System.Windows.Forms.Button();
            this.infolabel = new System.Windows.Forms.Label();
            this.button12 = new System.Windows.Forms.Button();
            this.button19 = new System.Windows.Forms.Button();
            this.axWindowsMediaPlayer1 = new AxWMPLib.AxWindowsMediaPlayer();
            ((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(634, 40);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(155, 68);
            this.button1.TabIndex = 0;
            this.button1.Text = "choose audio";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(292, 164);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "PlaySound";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(292, 257);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(151, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Windows Media Player (WMP)";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(292, 321);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(78, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "WaveOutWrite";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(292, 417);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(69, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "Direct Sound";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(292, 367);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(26, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "MCI";
            this.label5.Click += new System.EventHandler(this.label5_Click_1);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(479, 164);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(81, 33);
            this.button2.TabIndex = 6;
            this.button2.Text = "Play";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.PSplay);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(479, 247);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(81, 33);
            this.button3.TabIndex = 7;
            this.button3.Text = "Play";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.WMPplay);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(479, 311);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(81, 33);
            this.button4.TabIndex = 8;
            this.button4.Text = "Play";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.WOWplay);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(479, 357);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(81, 33);
            this.button5.TabIndex = 9;
            this.button5.Text = "Play";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.MCIplay);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(479, 407);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(81, 33);
            this.button6.TabIndex = 10;
            this.button6.Text = "Play";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.DSplay);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(593, 164);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(81, 33);
            this.button7.TabIndex = 11;
            this.button7.Text = "Stop";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.PSstop);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(593, 247);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(81, 33);
            this.button8.TabIndex = 12;
            this.button8.Text = "Stop";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.WMPstop);
            // 
            // button9
            // 
            this.button9.Location = new System.Drawing.Point(593, 311);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(81, 33);
            this.button9.TabIndex = 13;
            this.button9.Text = "Stop";
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.WOWstop);
            // 
            // button10
            // 
            this.button10.Location = new System.Drawing.Point(593, 357);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(81, 33);
            this.button10.TabIndex = 14;
            this.button10.Text = "Stop";
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.MCIstop);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(593, 407);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(81, 33);
            this.button11.TabIndex = 15;
            this.button11.Text = "Stop";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.DSstop);
            // 
            // button13
            // 
            this.button13.Location = new System.Drawing.Point(691, 247);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(81, 33);
            this.button13.TabIndex = 17;
            this.button13.Text = "Pause";
            this.button13.UseVisualStyleBackColor = true;
            this.button13.Click += new System.EventHandler(this.WMPpause);
            // 
            // button14
            // 
            this.button14.Location = new System.Drawing.Point(691, 311);
            this.button14.Name = "button14";
            this.button14.Size = new System.Drawing.Size(81, 33);
            this.button14.TabIndex = 18;
            this.button14.Text = "Pause";
            this.button14.UseVisualStyleBackColor = true;
            this.button14.Click += new System.EventHandler(this.button14_Click);
            // 
            // button15
            // 
            this.button15.Location = new System.Drawing.Point(691, 357);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(81, 33);
            this.button15.TabIndex = 19;
            this.button15.Text = "Pause";
            this.button15.UseVisualStyleBackColor = true;
            this.button15.Click += new System.EventHandler(this.button15_Click);
            // 
            // button16
            // 
            this.button16.Location = new System.Drawing.Point(691, 407);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(81, 33);
            this.button16.TabIndex = 20;
            this.button16.Text = "Pause";
            this.button16.UseVisualStyleBackColor = true;
            this.button16.Click += new System.EventHandler(this.button16_Click);
            // 
            // button17
            // 
            this.button17.Location = new System.Drawing.Point(902, 407);
            this.button17.Name = "button17";
            this.button17.Size = new System.Drawing.Size(81, 33);
            this.button17.TabIndex = 21;
            this.button17.Text = "Sound effects";
            this.button17.UseVisualStyleBackColor = true;
            // 
            // button18
            // 
            this.button18.Location = new System.Drawing.Point(989, 311);
            this.button18.Name = "button18";
            this.button18.Size = new System.Drawing.Size(81, 129);
            this.button18.TabIndex = 22;
            this.button18.Text = "record sound";
            this.button18.UseVisualStyleBackColor = true;
            // 
            // infolabel
            // 
            this.infolabel.AutoSize = true;
            this.infolabel.Location = new System.Drawing.Point(924, 68);
            this.infolabel.Name = "infolabel";
            this.infolabel.Size = new System.Drawing.Size(10, 13);
            this.infolabel.TabIndex = 23;
            this.infolabel.Text = "-";
            this.infolabel.Click += new System.EventHandler(this.infolabel_Click);
            // 
            // button12
            // 
            this.button12.Location = new System.Drawing.Point(789, 247);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(81, 33);
            this.button12.TabIndex = 24;
            this.button12.Text = "Resume";
            this.button12.UseVisualStyleBackColor = true;
            this.button12.Click += new System.EventHandler(this.WMPresume);
            // 
            // button19
            // 
            this.button19.Location = new System.Drawing.Point(789, 357);
            this.button19.Name = "button19";
            this.button19.Size = new System.Drawing.Size(81, 33);
            this.button19.TabIndex = 25;
            this.button19.Text = "Resume";
            this.button19.UseVisualStyleBackColor = true;
            this.button19.Click += new System.EventHandler(this.MCIresume);
            // 
            // axWindowsMediaPlayer1
            // 
            this.axWindowsMediaPlayer1.Enabled = true;
            this.axWindowsMediaPlayer1.Location = new System.Drawing.Point(1128, 40);
            this.axWindowsMediaPlayer1.Name = "axWindowsMediaPlayer1";
            this.axWindowsMediaPlayer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axWindowsMediaPlayer1.OcxState")));
            this.axWindowsMediaPlayer1.Size = new System.Drawing.Size(1, 1);
            this.axWindowsMediaPlayer1.TabIndex = 26;
            this.axWindowsMediaPlayer1.Enter += new System.EventHandler(this.axWindowsMediaPlayer1_Enter);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1452, 690);
            this.Controls.Add(this.axWindowsMediaPlayer1);
            this.Controls.Add(this.button19);
            this.Controls.Add(this.button12);
            this.Controls.Add(this.infolabel);
            this.Controls.Add(this.button18);
            this.Controls.Add(this.button17);
            this.Controls.Add(this.button16);
            this.Controls.Add(this.button15);
            this.Controls.Add(this.button14);
            this.Controls.Add(this.button13);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.button10);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.axWindowsMediaPlayer1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button13;
        private System.Windows.Forms.Button button14;
        private System.Windows.Forms.Button button15;
        private System.Windows.Forms.Button button16;
        private System.Windows.Forms.Button button17;
        private System.Windows.Forms.Button button18;
        private System.Windows.Forms.Label infolabel;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.Button button19;
        private AxWMPLib.AxWindowsMediaPlayer axWindowsMediaPlayer1;
    }
}

