using AxWMPLib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Media;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace widowappIG
{
    public partial class Form1 : Form
    {
        string file_path;
        SoundPlayer sound = null;
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string Cmd, StringBuilder StrReturn, int ReturnLength, IntPtr HwndCallback);
        bool mci = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click_1(object sender, EventArgs e)
        {

        }

        private void PSplay(object sender, EventArgs e)
        {
            if(file_path != "")
            {
                try
                {
                    sound = new SoundPlayer(file_path);
                    sound.Play();
                }
                catch(Exception ex)
                {
                    Console.WriteLine("The following error was detected in PSplay method: " + ex.Message);
                }
                finally
                {
                    sound.Dispose();
                }
            }
        }

        private void WMPplay(object sender, EventArgs e)
        {
            if(file_path != "")
            {
                axWindowsMediaPlayer1.URL = @file_path;
                axWindowsMediaPlayer1.Ctlcontrols.play();
            }
        }

        private void WOWplay(object sender, EventArgs e)
        {

        }

        private void MCIplay(object sender, EventArgs e)
        {
            if (file_path != "")
            {
                string command = $"open \"{file_path}\" type waveaudio alias audio";
                mciSendString("close audio", null, 0, IntPtr.Zero);
                mciSendString(command, null, 0, IntPtr.Zero);
                command = "play audio";
                mciSendString(command, null, 0, IntPtr.Zero);
                mci = true;
            }
        }

        private void DSplay(object sender, EventArgs e)
        {
            if (file_path != "")
            {

            }
        }

        private void PSstop(object sender, EventArgs e)
        {
            if(sound != null)
            {
                sound.Stop();
                sound.Dispose();
            }
        }

        private void WMPstop(object sender, EventArgs e)
        {
            if(axWindowsMediaPlayer1 != null)
            {
                axWindowsMediaPlayer1.Ctlcontrols.stop();
            }
        }

        private void WOWstop(object sender, EventArgs e)
        {

        }

        private void MCIstop(object sender, EventArgs e)
        {
            if (mci)
            {
                string command = "close audio";
                mciSendString(command, null, 0, IntPtr.Zero);
                mci = false;
            }
        }

        private void DSstop(object sender, EventArgs e)
        {

        }

        private void button12_Click(object sender, EventArgs e)
        {

        }

        private void WMPpause(object sender, EventArgs e)
        {
            if (axWindowsMediaPlayer1 != null)
            {
                axWindowsMediaPlayer1.Ctlcontrols.pause();
            }
        }

        private void button14_Click(object sender, EventArgs e)
        {

        }

        private void button15_Click(object sender, EventArgs e)
        {
            if (mci)
            {
                string command = "pause audio";
                mciSendString(command, null, 0, IntPtr.Zero);
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog()
            {
                FileName = "Select a WAV file",
                Filter = "WAV files (*.wav)|*.wav",
                Title = "Open WAV file"
            };
            
            if (openFileDialog1.ShowDialog() != DialogResult.OK)
            {
                infolabel.Text = "An error was found!";
                return;
            }
            file_path = openFileDialog1.FileName;
            infolabel.Text = "The file is accessed: "+file_path;
        }

        private void infolabel_Click(object sender, EventArgs e)
        {

        }

        private void WMPresume(object sender, EventArgs e)
        {
            if (axWindowsMediaPlayer1 != null)
            {
                axWindowsMediaPlayer1.Ctlcontrols.play();
            }
        }

        private void MCIresume(object sender, EventArgs e)
        {
            if (mci)
            {
                string command = "resume audio";
                mciSendString(command, null, 0, IntPtr.Zero);
            }
        }

        private void axWindowsMediaPlayer1_Enter(object sender, EventArgs e)
        {

        }
    }
}
