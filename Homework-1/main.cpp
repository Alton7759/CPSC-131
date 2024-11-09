#include <vector>
#include <iomanip>
#include <iostream>
#include <new>
#include <utility>         
#include <memory>


#include "GroceryItem.hpp"


int main() 
{
    std::cout << "Welcome tocla Kroger. Place grocery items into your shopping cart by entering each item's information\n";
    std::cout << "  enclose strubg ebtrues ub quotes, separate fields with comas\n";
    std::cout << "  for example: " << std::quoted("00016000306707") << ", " << std::quoted("Betty Crocker") << ", " << std::quoted("Betty Crocker Double Chocolate Chunk Cookie Mix") << ", " << "17.19\n" ;
    std::cout << "  Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";
    std::vector<std::unique_ptr<GroceryItem>> list;
    while (std::cin)
    {
        std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";    
        std::unique_ptr<GroceryItem> pointer = std::make_unique<GroceryItem>();
        if(std::cin >> *pointer){
            std::cout << "Item added to shopping cart: " << *pointer << "\n\n";
            list.push_back(std::move(pointer));
            continue;
        }
        std::cout << "Item added to shopping cart: " << *pointer << "\n\n";
        list.push_back(std::move(pointer));
       
        std::cout << "\n\n";
    }
    std::cout << "Here is an Itemized list of the items in your shopping cart: \n";
   for ( auto items = list.crbegin(); items != list.crend(); ++items){
            std::cout << **items;
            std::cout << '\n';
   }
}
