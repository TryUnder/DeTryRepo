using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Lab7
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            ResultText.Text = String.Empty;
            CurrentOperationText.Text = String.Empty;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            ResultText.Text = String.Empty;
            var button = sender as Button;
            var currentNumber = button.Name[button.Name.Length - 1];
            CurrentOperationText.Text += currentNumber;
        }

        private void ButtonAdd_Click(object sender, RoutedEventArgs e)
        {
            CurrentOperationText.Text = CurrentOperationText.Text + "+";
        }

        private void ButtonDivide_Click(object sender, RoutedEventArgs e)
        {
            CurrentOperationText.Text = CurrentOperationText.Text + "/";
        }

        private void ButtonMinus_Click(object sender, RoutedEventArgs e)
        {
            CurrentOperationText.Text = CurrentOperationText.Text + "-";
        }

        private void ButtonMultiply_Click(object sender, RoutedEventArgs e)
        {
            CurrentOperationText.Text = CurrentOperationText.Text + "*";
        }

        private void ButtonResult_Click(object sender, RoutedEventArgs e)
        {
            string operation = CurrentOperationText.Text;

            string[] addElements = operation.Split('+');
            if (operation.Contains('+'))
            {
                string[] elements = operation.Split('+');
                int result = int.Parse(elements[0]) + int.Parse(elements[1]);
                ResultText.Text = result.ToString();
            }

            if (operation.Contains('-'))
            {
                string[] elements = operation.Split('-');
                int result = int.Parse(elements[0]) - int.Parse(elements[1]);
                ResultText.Text = result.ToString();
            }

            if (operation.Contains('*'))
            {
                String[] elements = operation.Split('*');
                int result = int.Parse(elements[0]) * int.Parse(elements[1]);
                ResultText.Text = result.ToString();
            }

            if (operation.Contains('/'))
            {
                String[] elements = operation.Split('/');
                if(int.Parse(elements[1]) != 0)
                {
                    int result = int.Parse(elements[0]) / int.Parse(elements[1]);
                    ResultText.Text = result.ToString();
                }
            }
            
            CurrentOperationText.Text = String.Empty;
        }
    }
}
