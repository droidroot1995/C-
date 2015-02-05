using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Шаблон элемента пустой страницы задокументирован по адресу http://go.microsoft.com/fwlink/?LinkId=234238

namespace Системы_счисления.Common
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class Перевод_чисел : Page
    {
        public Перевод_чисел()
        {
            this.InitializeComponent();
        }

        /// <summary>
        /// Вызывается перед отображением этой страницы во фрейме.
        /// </summary>
        /// <param name="e">Данные о событиях, описывающие, каким образом была достигнута эта страница.  Свойство Parameter
        /// обычно используется для настройки страницы.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(Системы_счисления.MainPage));
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            int x, y, i, z, c, m, m1;
            string s, s1, s2;
            m1 = 0;
            s1 = null;
            s2 = null;
            int[] chisl = new int[256];
            x = Convert.ToInt32(textBox1.Text);
            y = Convert.ToInt32(textBox2.Text);
            i = 0;
            if (x == 0 | y == 0 | x == 1 | y == 1 | x > 16 | y > 16)
            {
                label5.Text = "Ошибка ввода системы счисления!";
            }
            else if (x == 10 & y <= 10)
            {
                s = textBox3.Text;
                if (s != "Число")
                {
                    z = Convert.ToInt32(textBox3.Text);
                    while (z > 0)
                    {
                        chisl[i] = z % y;
                        z = z / y;
                        i = i + 1;
                    }
                    for (c = i - 1; c > -1; c--)
                    {
                        s1 = s1 + chisl[c];
                    }
                    label5.Text = s1;
                }
                else label5.Text = "Ошибка ввода!";
            }
            else
            {
                s = textBox3.Text;
                if(s!="Число")
                {
                    m = s.Length;
                    for (c = 0; c < m - 1; c++)
                    {
                        if (s[c] == '1')
                        {
                            m1 = (m1 + 1) * x;
                        }
                        else if (s[c] == '2')
                        {
                            m1 = (m1 + 2) * x;
                        }
                        else if (s[c] == '3')
                        {
                            m1 = (m1 + 3) * x;
                        }
                        else if (s[c] == '4')
                        {
                            m1 = (m1 + 4) * x;
                        }
                        else if (s[c] == '5')
                        {
                            m1 = (m1 + 5) * x;
                        }
                        else if (s[c] == '6')
                        {
                            m1 = (m1 + 6) * x;
                        }
                        else if (s[c] == '7')
                        {
                            m1 = (m1 + 7) * x;
                        }
                        else if (s[c] == '8')
                        {
                            m1 = (m1 + 8) * x;
                        }
                        else if (s[c] == '9')
                        {
                            m1 = (m1 + 9) * x;
                        }
                        else if (s[c] == 'A')
                        {
                            m1 = (m1 + 10) * x;
                        }
                        else if (s[c] == 'B')
                        {
                            m1 = (m1 + 11) * x;
                        }
                        else if (s[c] == 'C')
                        {
                            m1 = (m1 + 12) * x;
                        }
                        else if (s[c] == 'D')
                        {
                            m1 = (m1 + 13) * x;
                        }
                        else if (s[c] == 'E')
                        {
                            m1 = (m1 + 14) * x;
                        }
                        else if (s[c] == 'F')
                        {
                            m1 = (m1 + 15) * x;
                        }
                    }
                    if (s[c] == '1')
                    {
                        m1 = (m1 + 1);
                    }
                    else if (s[c] == '2')
                    {
                        m1 = (m1 + 2);
                    }
                    else if (s[c] == '3')
                    {
                        m1 = (m1 + 3);
                    }
                    else if (s[c] == '4')
                    {
                        m1 = (m1 + 4);
                    }
                    else if (s[c] == '5')
                    {
                        m1 = (m1 + 5);
                    }
                    else if (s[c] == '6')
                    {
                        m1 = (m1 + 6);
                    }
                    else if (s[c] == '7')
                    {
                        m1 = (m1 + 7);
                    }
                    else if (s[c] == '8')
                    {
                        m1 = (m1 + 8);
                    }
                    else if (s[c] == '9')
                    {
                        m1 = (m1 + 9);
                    }
                    else if (s[c] == 'A')
                    {
                        m1 = (m1 + 10);
                    }
                    else if (s[c] == 'B')
                    {
                        m1 = (m1 + 11);
                    }
                    else if (s[c] == 'C')
                    {
                        m1 = (m1 + 12);
                    }
                    else if (s[c] == 'D')
                    {
                        m1 = (m1 + 13);
                    }
                    else if (s[c] == 'E')
                    {
                        m1 = (m1 + 14);
                    }
                    else if (s[c] == 'F')
                    {
                        m1 = (m1 + 15);
                    }
                    while (m1 > 0)
                    {
                        if (m1 % y == 10)
                        {
                            s1 = s1 + 'A';
                        }
                        else if (m1 % y == 11)
                        {
                            s1 = s1 + 'B';
                        }
                        else if (m1 % y == 12)
                        {
                            s1 = s1 + 'C';
                        }
                        else if (m1 % y == 13)
                        {
                            s1 = s1 + 'D';
                        }
                        else if (m1 % y == 14)
                        {
                            s1 = s1 + 'E';
                        }
                        else if (m1 % y == 15)
                        {
                            s1 = s1 + 'F';
                        }
                        else s1 = s1 + (m1 % y);
                        m1 = m1 / y;
                        i = i + 1;
                    }
                    for (c = i - 1; c > -1; c--)
                    {
                        s2 = s2 + s1[c];
                    }
                    label5.Text = s2;
            }
            else label5.Text = "Ошибка ввода!";
            }
        }
    }
}
