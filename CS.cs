using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

// Chart_CS - name of your project / namespace of your project
namespace Chart_CS
{
    // Form1 - name of your form
    public partial class Form1 : Form
    {
        // Fields
        private double a, b, h;
        private double x, y;

        public Form1()
        {
            InitializeComponent();
        }

        // Button click handlers (created by clicking on buttons!): 

        // Create the chart
        private void построитьГрафикToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (checkBox_cos.Checked == false && checkBox_sin.Checked == false)
            {
                MessageBox.Show("Choose at least one chart!", "Attention!");
                return;
            }

            if(textBox_a.Text == "" || textBox_b.Text == "" || textBox_h.Text == "")
            {
                MessageBox.Show("Default parameters!", "Attention!");
                DefaultParams();
            }
            else
            {
                a = Convert.ToDouble(textBox_a.Text);
                b = Convert.ToDouble(textBox_b.Text);
                h = Convert.ToDouble(textBox_h.Text);
            }

            if (checkBox_cos.Checked)
            {
                x = a;
                this.chart.Series[0].Points.Clear();
                while (x <= b)
                {
                    y = Math.Cos(x);
                    this.chart.Series[0].Points.AddXY(x, y);
                    x += h;
                }
            }

            if (checkBox_sin.Checked)
            {
                x = a;
                this.chart.Series[1].Points.Clear();
                while (x <= b)
                {
                    y = Math.Sin(x);
                    this.chart.Series[1].Points.AddXY(x, y);
                    x += h;
                }
            }
        }

        // Clear the chart 
        private void очиститьГрафикToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (checkBox_cos.Checked == false && checkBox_sin.Checked == false)
            {
                MessageBox.Show("Choose at least one chart!", "Attention!");
                return;
            }

            if (checkBox_cos.Checked)
            {
                this.chart.Series[0].Points.Clear();
            }

            if (checkBox_sin.Checked)
            {
                this.chart.Series[1].Points.Clear();
            }
        }

        // Exit 
        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(MessageBox.Show("Exit?", "Attention!", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        // Additional method
        private void DefaultParams()
        {
            a = -10;
            b = 10;
            h = 0.1;
        }
    }
}
