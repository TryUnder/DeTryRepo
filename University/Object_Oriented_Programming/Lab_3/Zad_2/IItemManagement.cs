using System;
namespace Zad_2{
    public interface IItemManagement{
        public void ShowAllItems();
        public Item FindItemBy(int id);
        public Item FindItemBy(string title);
    }
}