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
using Student.BLL;

namespace Student.WpfApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public IList<StudenT> Students { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Students = new List<StudenT>
            {
                new StudenT(){ Firstname = "Jan", Surname = "Kowalski", Faculty = "WIMII", Id = 1010 },
                new StudenT(){ Firstname = "Michał", Surname = "Nowak", Faculty = "WIMII", Id = 1011 },
                new StudenT(){ Firstname = "Jacek", Surname = "Makieta", Faculty = "WIMII", Id = 1012 }
            };
            gridstudent.Columns.Add(new DataGridTextColumn() { Header = "First Name", Binding = new Binding("Firstname")});
            gridstudent.Columns.Add(new DataGridTextColumn() { Header = "Last Name", Binding = new Binding("Surname")});
            gridstudent.Columns.Add(new DataGridTextColumn() { Header = "Faculty", Binding = new Binding("Faculty")});
            gridstudent.Columns.Add(new DataGridTextColumn() { Header = "Id", Binding = new Binding("Id") });
            gridstudent.AutoGenerateColumns = false;
            gridstudent.ItemsSource = Students;
            
        }

        private void AddStudent_Click(object sender, RoutedEventArgs e)
        {
            AddStudentWindow newWindowDialog = new AddStudentWindow();
            newWindowDialog.ShowDialog();
            if (newWindowDialog.DialogResult == true)
                Students.Add(newWindowDialog.student);
            gridstudent.Items.Refresh();
        }

        private void Delete_student_Click(object sender, RoutedEventArgs e)
        {
            if (gridstudent.SelectedItem is StudenT studentToRemove)
            {
                Students.Remove(studentToRemove);
                gridstudent.Items.Refresh();
            }
        }
    }
}
