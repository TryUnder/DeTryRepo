import os 

sciezka=input("Proszę wprowadzić scieżkę do pliku: ") 
file_exist = os.path.exists(sciezka) 
if file_exist == 1:
    print(file_exist)
    root,extension=os.path.splitext(sciezka)
                                            
    print(extension)
else:
    print("Ścieżka nie istnieje!")