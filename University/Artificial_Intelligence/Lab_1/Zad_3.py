array = "TTAGTAGGGTTGTCCAT"

def calculate_length(array):
    return print("Dlugosc wynosi:",len(array))

def validate_string(array):
    for i in range(0,len(array)-1,1):
        if ((array[i] == 'A' and array[i+1] == 'T') or (array[i] == 'T' and array[i+1] == 'A')):
            print("validated pair", i, "AT or TA")
        elif ((array[i] == 'C' and array[i+1] == 'G') or (array[i] == 'G' and array[i+1] == 'C')):
            print("validated pair", i, "CG or GC")
        else:
            print("pair,",i,"not validated")
            
def generate_complementary_array(array):
    new_array=''
    for i in range(0,len(array)-1,1):
        if (array[i]) == 'A':
            new_array = new_array + 'T'
        elif (array[i]) == 'T':
            new_array = new_array + 'A'
        elif (array[i]) == 'C':
            new_array = new_array + 'G'
        elif (array[i]) == 'G':
            new_array = new_array + 'C'
    print(array)
    print(new_array)
    
def reverse_array(array):
    arr = list(array)
    arr.reverse()
    print("Before reverse:",array)
    print("After reverse:",arr)
    
def calculate_GG_pairs(array):
    counter = 0
    for i in range(0,len(array) - 1, 1):
        if array[i] == 'G' and array[i+1] == 'G':
            counter+1
    print("GG pairs:",counter)

calculate_length(array)
validate_string(array)
generate_complementary_array(array)
reverse_array(array)
calculate_GG_pairs(array)