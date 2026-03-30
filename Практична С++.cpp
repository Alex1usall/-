
//Завання 1

// #include <iostream>
// #include <ctime>
// #include <cstdlib>

// int main() 
// {
//     srand(time(0));
//     int array [10];
    
//     for (int i = 0; i < 10; i++){
      
//       array[i] = rand() % 100;
//     }
    
//     std::cout << "Your array: ";
//     for (int i = 0; i < 10; i++){
//       std::cout << array[i]<< " ";
//     }
    
// }

//Завдання 2

// #include <iostream>


// int main(){
  
//   int n = 0;
  
//   std::cout << "Put how many corners you want: " << std::endl;
//   std::cin >> n;
  
//   int x[20];
//   int sum = 0;
  
//   std::cout << "Write your coners: "<< std::endl;
//   for (int i = 0; i < n; i++){
    
//     std::cin >> x[i];
    
//     sum += x[i];
//   }
//   std::cout << "Sum of your corners = " << sum << std::endl;
  
//   if (sum == 180*(n-2)){
//     std::cout << "The polygon exists" << std::endl;
//   }
//   else {
//     std::cout << "The poygon can't exist" << std::endl;
//   }
// }

//Завдання 3 

// #include <iostream>
// #include <ctime>
// #include <cstdlib>

// int main(){
// std::cout << "White a array size: " << std::endl;
// int size = 0;

// std::cin >> size; 

// int array [100]; 

// srand(time(0));

// for (int i = 0; i < size; i++){
    
//     array[i] = rand() % 100;
//     }
    
// std::cout << "Array";
// for (int i = 0; i < size; i++){
//     std::cout << array[i] << " " << std::endl;
//     }
    
// std::cout << "White numver of array element, which you want change: " << std::endl;

// int element = 0;
// std::cin >> element;

// std::cout << "Enter the number you want to change to: " << std::endl;

// int userNum = 0; 
// std::cin >> userNum;

// for (int i = 0; i < size; i++){

//     array[element] = userNum;
//     }
    
// std::cout << "Your modified array: ";
// for (int i = 0; i < size; i++){
//     std::cout << array[i] << " ";
//     }
// }

//Завдання 4

//Pass

//Завдання 5

// #include <iostream>
// #include <ctime>

// int main(){
    
//     int array[100];
    
//     std::cout <<"Enter array size: " <<std::endl;
//     int size = 0;
//     std::cin >> size;
    
//     srand(time(0));
    
//     for (int i = 0; i < size; i++){
        
//         array [i] = rand() % 100;
//         }
        
//     std::cout << "Array: ";
//     for (int i = 0; i < size; i++){
//         std::cout << array[i] << " ";
//         }
    
//     std::cout << "\nSelect the order in which to check the array (1 - ascending, 2 - descending)" << std::endl;
    
//     int choice = 0;
    
//     std::cin >> choice;
    
//     bool order = true;
    
//     if (choice == 1) {
        
//         for (int i = 0; i < size - 1; i++) {
//             if (array[i] > array[i + 1]) {
//                 order = false;
//                 break;
//             }
//         }
//         if (order)
//             std::cout << "Array is in ascending order" << std::endl;
//         else
//             std::cout << "Array is not in ascending order" << std::endl;
//     }
//     else if (choice == 2) {
        
//         for (int i = 0; i < size - 1; i++) {
//             if (array[i] < array[i + 1]) {
//                 order = false;
//                 break;
//             }
//         }
//         if (order)
//             std::cout << "Array is in descending order" << std::endl;
//         else
//             std::cout << "Array is not in descending order" << std::endl;
//     }
//     else {
//         std::cerr << "Error" << std::endl;
//     }

// }
