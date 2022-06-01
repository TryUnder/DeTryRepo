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
using System.Windows.Shapes;
using Student.BLL;

namespace Student.WpfApp
{
    public partial class AddStudentWindow : Window
    {
        public StudenT student { get; set; }
        public AddStudentWindow()
        {
            InitializeComponent();
            student = new StudenT();
        }

        private void AddStudent_Click(object sender, RoutedEventArgs e)
        {
            student.Firstname = firstname.Text;
            student.Surname = surname.Text;
            student.Faculty = faculty.Text;
            if (!int.TryParse(idTextBox.Text, out int Id))
            {
                MessageBox.Show(messageBoxText: "Student is not a number.");
                return;
            }
            DialogResult = true;
        }
    }
}
