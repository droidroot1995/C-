using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace камень_ножницы_бумага
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        const int Max = 10;
        int Object, Comp, Ty, Vvod, Button;
        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text += "    Version:  " + System.Reflection.Assembly.GetExecutingAssembly().GetName().Version.ToString();
            Random rand = new Random();
            Object = rand.Next(0, 2);
            Ty = 0;
            Comp = 0;
            label3.Text = Convert.ToString(Ty);
            label4.Text = Convert.ToString(Comp);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            Vvod = 0;
            if (Vvod == Object)
            {
                Ty = Ty + 0;
                Comp = Comp + 0;
                label1.Text = "Камень";
                label2.Text = "Камень";
                pictureBox5.Image = pictureBox2.Image;
                pictureBox6.Image = pictureBox2.Image;
            }
            if (Object == 1)
            {
                Comp++;
                label1.Text = "Камень";
                label2.Text = "Бумага";
                pictureBox5.Image = pictureBox2.Image;
                pictureBox6.Image = pictureBox3.Image;
            }
            if (Object == 2)
            {
                Ty++;
                label1.Text = "Камень";
                label2.Text = "Ножницы";
                pictureBox5.Image = pictureBox2.Image;
                pictureBox6.Image = pictureBox4.Image;
            }
            if (Ty == Max)
            {
                label5.Text = "Вы выиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                  Random rnd = new Random();
            Object = rnd.Next(0, 2);
            Ty = 0;
            Comp = 0;
            label3.Text = Convert.ToString(Ty);
            label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            if (Comp == Max)
            {
                label5.Text = "Вы проиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                    Random rnd = new Random();
                    Object = rnd.Next(0, 2);
                    Ty = 0;
                    Comp = 0;
                    label3.Text = Convert.ToString(Ty);
                    label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            label3.Text = Convert.ToString(Ty);
            label4.Text = Convert.ToString(Comp);
            Random rand = new Random();
            Object = rand.Next(0, 2);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            Vvod = 1;
            if (Vvod == Object)
            {
                Ty = Ty + 0;
                Comp = Comp + 0;
                label1.Text = "Бумага";
                label2.Text = "Бумага";
                pictureBox5.Image = pictureBox3.Image;
                pictureBox6.Image = pictureBox3.Image;
            }
            if (Object == 0)
            {
                Ty++;
                label1.Text = "Бумага";
                label2.Text = "Камень";
                pictureBox5.Image = pictureBox3.Image;
                pictureBox6.Image = pictureBox2.Image;
            }
            if (Object == 2)
            {
                Comp++;
                label1.Text = "Бумага";
                label2.Text = "Ножницы";
                pictureBox5.Image = pictureBox3.Image;
                pictureBox6.Image = pictureBox4.Image;
            }
            if (Ty == Max)
            {
                label5.Text = "Вы выиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                    Random rnd = new Random();
                    Object = rnd.Next(0, 2);
                    Ty = 0;
                    Comp = 0;
                    label3.Text = Convert.ToString(Ty);
                    label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            if (Comp == Max)
            {
                label5.Text = "Вы проиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                    Random rnd = new Random();
                    Object = rnd.Next(0, 2);
                    Ty = 0;
                    Comp = 0;
                    label3.Text = Convert.ToString(Ty);
                    label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            label3.Text = Convert.ToString(Ty);
            label4.Text = Convert.ToString(Comp);
            Random rand = new Random();
            Object = rand.Next(0, 2);
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            Vvod = 2;
            if (Vvod == Object)
            {
                Ty = Ty + 0;
                Comp = Comp + 0;
                label1.Text = "Ножницы";
                label2.Text = "Ножницы";
                pictureBox5.Image = pictureBox4.Image;
                pictureBox6.Image = pictureBox4.Image;
            }
            if (Object == 0)
            {
                Comp++;
                label1.Text = "Ножницы";
                label2.Text = "Камень";
                pictureBox5.Image = pictureBox4.Image;
                pictureBox6.Image = pictureBox2.Image;
            }
            if (Object == 1)
            {
                Ty++;
                label1.Text = "Ножницы";
                label2.Text = "Бумага";
                pictureBox5.Image = pictureBox4.Image;
                pictureBox6.Image = pictureBox3.Image;
            }
            if (Ty == Max)
            {
                label5.Text = "Вы выиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                    Random rnd = new Random();
                    Object = rnd.Next(0, 2);
                    Ty = 0;
                    Comp = 0;
                    label3.Text = Convert.ToString(Ty);
                    label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            if (Comp == Max)
            {
                label5.Text = "Вы проиграли!";
                DialogResult Button = MessageBox.Show("Новая Игра?", "Новая Игра?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (Button == DialogResult.Yes)
                {
                    Random rnd = new Random();
                    Object = rnd.Next(0, 2);
                    Ty = 0;
                    Comp = 0;
                    label3.Text = Convert.ToString(Ty);
                    label4.Text = Convert.ToString(Comp);
                }
                else
                    Close();
            }
            label3.Text = Convert.ToString(Ty);
            label4.Text = Convert.ToString(Comp);
            Random rand = new Random();
            Object = rand.Next(0, 2);
        }
    }
}
