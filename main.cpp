//--------------------------------------------------------------------------------//
//  Author: Marlon Schellhorn & Michael Wu
//  Date:January 21, 2022
//  Program: Replit C++
//  Purpose: 
//
//
//
//
//
//
//
//
//
//--------------------------------------------------------------------------------//
#include <stdio.h>
//Bringing in libraries
#include <iostream>
#include <thread>
#include <chrono>  
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>
#include<sstream>
//Not needed
#include <stdlib.h>

using namespace std;
int times = 250;
//Declaring functions
void screen(int& animation, int time, string& weather);
void rod(int rodPowerBase[7], int rodTypes[7], int& rodPower);
void bait(int baitPowerBase[7], int baitTypes[5], int& baitPower);
void menu(int fish[25], int dailyFish[25], int rodTypes[7], int baitTypes[5], int rodInventory[7], int baitInventory[5], int miscInventory[8], double& purse, int lifetimeFish[25], int& totalDays);
void nineA (int fish[25], int dailyFish[25],int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather);
void tenA (int fish[25], int dailyFish[25],int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather);
void elevenA (int fish[25], int dailyFish[25],int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather);
void twelveP (int fish[25], int dailyFish[25],int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather);
void oneP (int fish[25], int dailyFish[25],int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather);

//Starting main program
int main() 
{
    //std::ostream file("/tmp/audio");
  //Declaring variables
	int time = 0;
  int y = 0;
	int inf = 0;
	int test = 0;
  string weather = "Clear Skys";
  int minute = 0;
	int minnow = 0, bass = 0;
	int boot = 0;
  int fish[25] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  int lifetimeFish[25] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  int craftedItems[1] = {0};
  string gameExit = "No";
  //Selected rod
  int rodTypes[7] = {1,0,0,0,0,0,0};
  //Selected Bait
  int baitTypes[5] = {0,0,0,0,0};
  //All your rods
  int rodInventory[7] = {1,1,1,1,1,1,1};
  int miscInventory[8] = {100,100,100,100,100,100,100,100};
  int baitInventory [5] = {100,100,100,100,100};
  int rodPowerBase[7] = {0,12,35,20,33,90,-10};
  //ghost rod is 40
  int baitPowerBase[5] = {90, 15, 17, 21, 25};
  int rodPower = 0;
  int baitPower = 0;
  //string fishName[3] = {"Minnow", "Boot", "Bass"};
  double purse = 100000;
  int totalDays = 0;
  int rainCheck = 0;
  int rainLength = 0;

  //The entire game, loops while the user wants to play
  while (gameExit == "No")
  {
    //Declaring & resetting the amount of fish caught that day
    int dailyFish[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Calculates the rod and bait 'power' for the day depending on what the user selects (effects how often you catch a fish and the rarity of the fish you catch)
    rod(rodPowerBase, rodTypes, rodPower);
    bait(baitPowerBase, baitTypes, baitPower);
    //Calls to the 9am fishing time function
    nineA(fish, dailyFish, rodPower, baitPower, rainCheck, rainLength, weather);
        tenA(fish, dailyFish, rodPower, baitPower, rainCheck, rainLength, weather);
            elevenA(fish, dailyFish, rodPower, baitPower, rainCheck, rainLength, weather);
                twelveP(fish, dailyFish, rodPower, baitPower, rainCheck, rainLength, weather);
                    oneP(fish, dailyFish, rodPower, baitPower, rainCheck, rainLength, weather);
    //Adding the fish caught for the day to the fish you have
    for (y=0;y<25;y++)
    {
      fish[y] += dailyFish[y];
    }
    //Adding the fish caught for the day to the total amount of fish you have caught over the game
    for (y=0;y<25;y++)
    {
      lifetimeFish[y] += dailyFish[y];
    }    
    //Resets bait power since bait is soncumed after a fishing day
    baitPower = 0;
    //Keeps track of the total amount of days passed
    totalDays++;
    //Menu is opened after the day is finished so the user can perform actions
    menu(fish, dailyFish, rodTypes, baitTypes, rodInventory, baitInventory, miscInventory, purse, lifetimeFish, totalDays);
  }
}

//Rod function
void rod(int rodPowerBase[7], int rodTypes[7], int& rodPower)
{
  //Declaring variables
  int i = 0;
  int currentRod = -1;

  //cout << "Working1";

  //Loop for all the different rod types
  for(i=0;i<7;i++)
  {
    //If the rod is selected
    if(rodTypes[i] > 0)
    {
      //Set the rod power to the power of the selected rod and keep track of which rod was selected
      rodPower = rodPowerBase[i];
      currentRod = i;
    }
    //Reset all rod slections to zero
    rodTypes[i] = 0;
  }
  //Set the rod that is selected back to 1 so that the rod is still used after each day
  rodTypes[currentRod]=1;
  //cout << "\n" << rodPower << "\n";
}

//Bait function
void bait(int baitPowerBase[5], int baitTypes[5], int& baitPower)
{
  //Declaring variables
  int i = 0;

  //cout << "Working1";

  //Loops for all the different bait types
  for(i=0; i<5; i++)
  {
    //If the bait is selected
    if(baitTypes[i] > 0)
    {
      //Set the bait power to the power of the selected bait
      baitPower = baitPowerBase[i];
    }
    //Reset all the selected baits to zero
    baitTypes[i] = 0;
  }
  //cout << "\n" << baitPower << "\n";
}

//The 9 am fishing time function
void nineA (int fish[25], int dailyFish[25], int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather)
{
  //Setting the random seed for the random number generated
  srand((int)time(0));

  //Declaring variables that are used in function
  int randNum = 0;
  int i=0;
  int time = 9;
  int y = 0;
  int animation = 0;
  int rainRandNum = 0;
  int rainPower = 0;
    
  rainRandNum = rand() % 20 + 1;

  if (rainRandNum == 1)
  {
    //rainLength = rand() % 3 + 1;
    rainLength = 3;
    rainPower = 5;
    weather = "Rainy";
  }
  else{
    weather = "clear Skys";
  }


  //Looping 10 times during this time period and every second checks if a fish is caught
  for (i=0;i<10;i++)
  {
    //this_thread::sleep_for(chrono::milliseconds(500));
    //Displays the fishing animation by calling to screen function
    screen(animation,time, weather);
    //------------------------------------//
    //Generates random number to see if a fish is caught
    randNum = rand() % (100 - rodPower - rainPower) ;
    //If the random number is 0
    //Should be 10 normally

    //If a fish is caught
    if (randNum < 10)
    {
      //Generate another random number
      //randNum = rand() % [100+30-15] + 15;

      //Generate another random number to see what fish is caught 
      randNum = rand() % (100-baitPower-rainPower) + (1+baitPower+rainPower);

      //Depending on the random number, decides which fish was caught
      if (randNum <= 20)
      {
        //Outputs the fish that was caught
        cout << "Boot\n";
        //Adds a fish to the total amount of that fish
        dailyFish[0]++;
      }
      else if (randNum > 20 && randNum <= 75)
      {
        cout << "Minnow\n";
        dailyFish[1]++;
      }
      else if (randNum > 75 && randNum <= 100)
      {
        cout << "Shrimp\n";
        dailyFish[2]++;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(times));
    cout<<"\n";

  }
}


//Screen function
void screen(int & animation, int time, string& weather)
{
  //Clars the screen
  cout << "\033[2J\033[0;0H";
  
  //Displays a different part of the animation depending on the time
  switch(animation)
  {
    case(0):
      cout << "________________________________________________________________________________\n";
      cout << "__________________O__/:________________________________________-________________\n";
      cout << "___/[][][][][][][/|{/[][][][][]/_____________-__________________________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/________________________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/________________________________________________\n";
      cout << "_____________________________________________________________-__________________\n";
      cout << time << ":00\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(1):
      cout << "________________________________________________________________________________\n";
      cout << "__________________O__/:_______________________________________-_________________\n";
      cout << "___/[][][][][][][/|{/[][][][][]/________________________________________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/_______________-_______________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/________________________________________________\n";
      cout << "__________________________________________________-____________________-________\n";
      cout << time << ":10\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(2):
      cout << "___________________________________________________________-____________________\n";
      cout << "__________________O__/:___________________-_______________________________-_____\n";
      cout << "___/[][][][][][][/|{/[][][][][]/____________________-___________________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________________________________________-___\n";
      cout << "_/[][][][][][][][][][][][][][][/_______________________________-________________\n";
      cout << "____________________________________________-___________________________________\n";
      cout << time << ":15\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(3):
      cout << "________________________________________________________________________________\n";
      cout << "__________________O__/:_______________________________-_________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/___________-____________________________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/____-______________________-___________________\n";
      cout << "_/[][][][][][][][][][][][][][][/________________________________________________\n";
      cout << "______________________________________________-________________-________________\n";
      cout << time << ":20\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(4):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-___________________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/________________________-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-___________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":30\n";
      cout<< "Weather: " << weather << "\n";
    break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    case(5):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-__________5________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/________________________-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-___________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":40\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(6):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-___________________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/_______________6________-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-___________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":45\n"; 
      cout<< "Weather: " << weather << "\n";
    break;
    case(7):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-___________________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/_______________7________-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-___________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":50\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(8):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-___________________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/________________________-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-______8____________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":55\n";
      cout<< "Weather: " << weather << "\n";
    break;
    case(9):
      cout << "___________________________________________-____________________________________\n";
      cout << "__________________O__/:_____________-___________________________________-_______\n";
      cout << "___/[][][][][][][/|{/[][][][][]/____________________9___-_______________________\n";
      cout << "__/[][][][][][][][/\\[][][][][][/___________-___________________________________\n";
      cout << "_/[][][][][][][][][][][][][][][/_____________________________-__________________\n";
      cout << "____________________________________-________________________________________-__\n";
      cout << time << ":59\n";
      cout<< "Weather: " << weather << "\n";
    break;
    
    default:

    break;
  }
  //Cycles to next part of animation
  animation++;
  //If the animation cycle is complete, reset
  if (animation > 9)
  {
    animation = 0;
  }
  else
  {
    //
  }

}

//Menu function
void menu(int fish[25], int dailyFish[25], int rodTypes[7], int baitTypes[5], int rodInventory[7], int baitInventory[5], int miscInventory[8], double& purse, int lifetimeFish[25], int& totalDays)
{
  //Declaring variables
  string option = "";
  int rodNum;
  int baitNum;
  string option2= "";
  int craftConfirm = 0;
  double itemValue[25] = {0.01, 0.05, 0.25, 0.30, 0.70, 0.50, 0.80, 1.50, 2.75, 5, 7, 7.75, 6, 6.5, 8, 10, 15, 13, 100, 6666, 5000, 100000, 8000, 20000, -1};
  double shopValue[7] = {10, 150, 100, 200, 15, 5000, 15000};
  int sellNum=0;
  string sellString = "DEFUALT";
  int shopNum =0;
  string shopString = "DEFAULT";
  int beastNum = 0;
  string beastString = "DEFUALT";
  int sellAmount= 0;
  string sellChar; 
  int length = 0;
  string exitDesc = "DEFUALT";
  char craftConfirmA;
  int percentFish = 0;

  //------------------------------------------------------------------//
  string rodNames[7] = {"Starter Rod", "Reinforced Fishing Pole", "Fiberglass Fishing Pole", "Lead Rod", "Lucifer's Cast", "Ghost Rod", "Negative Rod"};
  //------------------------------------------------------------------//
  string fishName[25] = {"Boots", "Minnow", "Shrimp", "Sunfish", "Carp", "Smallmouth Bass", "Largemouth Bass", "Pike", "Seabass", "Rainbow Trout", "Neon Tetra", "Prismite","Bluefin Tuna", "Atlantic Cod", "Night Soul Fish", "Zombie Fish", "Ghost Fish", "Hagfish", "Marlin", "Demonic Hellfish", "Lunch Fish", "Godfish", "Clouded Fog Fish", "Radioactive Anglerfish", "Negative Fish"};

  string beastName[25] = {"Boots", "Minnow", "Shrimp", "Sunfish", "Carp", "Smallmouth Bass", "Largemouth Bass", "Pike", "Seabass", "Rainbow Trout", "Neon Tetra", "Prismite","Bluefin Tuna", "Atlantic Cod", "Night Soul Fish", "Zombie Fish", "Ghost Fish", "Hagfish", "Marlin", "Demonic Hellfish", "Lunch Fish", "Godfish", "Clouded Fog Fish", "Radioactive Anglerfish", "Negative Fish"};
  //------------------------------------------------------------------//
  string baitNames[5] = {"Minnow Bucket", "Apprentice Bait", "Chum", "Enchanted Fairy Bait", "High Quaility Bait"};
  //------------------------------------------------------------------//
  string miscNames[8] = {"Bucket", "Soul Case", "Pixie Dust", "Strange Flesh", "Tourtured Soul", "Ectoplasm", "Radioactive Plating", "Power Dampaner"};
  //------------------------------------------------------------------//
  string shopNames[7] = {"Bucket", "Soul Case", "Pixie Dust", "Strange Flesh", "Starter Rod", "Reinforced Fishing Pole", "Fiberglass Fishing Pole"};

  string fishDesc[25] = {"Someone's old, stinky boot.", "A small fish.", "A small, long crustacean.", "A small, nest building fish with a sharp spine.", "A large, stinky relative of the goldfish.", "A popular sport fish, characterized by its smaller size compared to the largemouth bass.", "A popular sport fish, characterized by its larger size compared to the smallmouth bass.", "A long bodied, pointy toothed fish.", "A black-scaled relative of the large and smallmouth bass found only in the sea.", "A pink-striped and black-dotted fish that appears rainbow under light.", "A small fish known for its neon blue stripe and bright red tail.", "A shiny fish that reflects rainbow light off its skin.", "A large, dark-blue fish that can weigh up to 250kg.", "A fish known for its light and fluffy meat.", "A dark, nebulous fish that exerts purple energy.", "A half decayed fish, emanating a foul stench. Somehow, it is still “alive”.", "(gonna be really cool)", "An ugly, eel-like fish that is known for its ability to produce large amounts of slime.", "A long bodied fish known for its spear-like nose and the high speeds it can achieve underwater.", "A fish pulled from the depths of hell.", "This fish goes great on sandwiches.", "No, you read that right, it’s not a goldfish.", "A fish that appears to be clouded in fog.", "After years of illegal nuclear waste dumping, this mutant fish has been pulled out of the depths.", "This fish is composed of trace amounts of negative matter and brings bad fortune to those who fish it."};
  int i = 0;
  int fishNameLength = 0;
  char userCraft = '0';
  string userCraftB = "S";
  //userCraftB is an integer, while craftC

  //Clears the screen
  cout << "\033[2J\033[0;0H";

  //For all 25 fish
  for (i=0;i<25;i++)
  {
    //If you caught a particular fish that day, then display it with how many you caught
    if (dailyFish[i] > 0)
    {
      cout<<fishName[i] << " x "<< dailyFish[i] << "\n";
    }
  }

  //Displays your total money and the total amount of days passed
  cout<<"Purse - $" <<purse << "       Total Days: " <<totalDays << "\n\n";

  /*
  for (i = 0; i < 25; i ++)
  {
    cout << lifetimeFish[i] << "\n";
  }
  */
  
  //Shows the user their options to choose from
  cout<<"I- Inventroy\n";
  cout<<"C- Continue\n";
  cout<<"S- Shop\n";
  cout<<"B- Beastaery\n";

  //They enter what they want to do
  cin>>option;

  //If they choose inventory
  if (option == "I")  
  {
    //Clear screen and display what they have 
    cout << "\033[2J\033[0;0H";
    while(option == "I")
    {
      //Fish they have
      cout<<"[==== F I S H ======================================]\n";
      for (i=0;i<25;i++)
      {
        if (fish[i] > 0)
        {
          cout << i+1 << ". ";
          cout<<fishName[i];
          cout << " x ";
          cout<<fish[i];
          cout<<"\n";
        }
        else
        {
          //Combine couts to make less lines
          cout << i+1 << ". ";
          fishName[i].assign(10, '?');
          cout<<fishName[i];
          cout << " x ";
          cout<<fish[i];
          cout<<"\n";
        }
      }
      //Rods they have
      cout<<"\n";
      cout<<"[==== R O D S ======================================]\n";
      for (i=0;i<7;i++)
      {
        cout << i+1 << ". ";
        cout<<rodNames[i];
        cout<< " x ";
        cout<<rodInventory[i];
        cout<<"\n";
      }
      //Baits they have
      cout<<"\n";
      cout<<"[==== B A I T S ====================================]\n";
      for (i=0;i<5;i++)
      {
        cout << i+1 << ". ";
        cout<<baitNames[i];
        cout<< " x ";
        cout<<baitInventory[i];
        cout<<"\n";
      }
      //Misc. items they have
      cout<<"\n";
      cout<<"[==== M I S C E L L A N E O U S ====================]\n";
      for (i=0;i<8;i++)
      {
        cout << i+1 << ". ";
        cout<<miscNames[i];
        cout<< " x ";
        cout<<miscInventory[i];
        cout<<"\n";
      }      
      //Options that the user can choose from
      cout<<"\n";
      cout<<"C - Craft      ";
      cout<<"S - Sell       ";
      cout<<"U - Use        ";
      
      //User input option
      cin>>option;
      userCraftB = "F";   
      //If the user wants to craft
      if (option == "C")
      {
        //Clears screen and loops while the user still wants to craft
        cout << "\033[2J\033[0;0H";
        //Had to reset to not E so that it would reenetr the loop, aslo finding the correct spot to do so       
        while(userCraftB != "E")
        {
          cout << "\033[2J\033[0;0H";

          //Displays craftable baits
          for (i=0;i<5;i++)
          {
            cout << i+1 << ". ";
            cout<<baitNames[i];
            cout<<"\n";
          }   
          //Displays craftable miscs
          for (i=4;i<8;i++)
          {
            cout << i+2 << ". ";
            cout<<miscNames[i];
            cout<<"\n";
          }
          //Displays craftable rods
          for (i=3;i<7;i++)
          {
            cout << i+7 << ". ";
            cout<<rodNames[i];
            cout<<"\n";
          }          

          //Asks the user what they want tocraft
          cout<<"Enter number of receipe you want to craft: \n";

          //User input option
          cin>>userCraftB;
          //userCraftB++;

          //----------------- CRAFTING RECIPE 1 -----------------//
          //Same format applies for all recipes except for recipes 10-13
          //IF the user shooses the first recipe
          if(userCraftB == "1")
          {
            //Displays name of item, description,required materials, and asks how much they want to craft
            cout << "\033[2J\033[0;0H";
            cout<<"Minnow Bucket\n";
            cout<<"A bucket full of minnows, that’s it.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Minnow x 10]\n[Bucket x 1] \n\n";
            cout<<"Enter the amount (units) of Minnow Buckets you want to craft OR E to exit ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            //If they want to exit
            if (craftConfirmA == 'E')
            {
              //Exit them back to craft menu
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            //Else checks if they can craft the recipe
            else if ((fish[1] >= (10*craftConfirm)) && (miscInventory[0] >= (1*craftConfirm)))
            {
              //Shows that they crafted the recipe
              cout << "Crafted " << craftConfirm << " Minnow Bucket(s)";
              baitInventory[0] += craftConfirm;
              fish[1] -= 10*craftConfirm;
              miscInventory[0] -= 1*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            //Else they cannot craft the recipe
            else
            {
              //Tells user that they cannot craft the recipe
              cout<<"You do have enough resourses!\n";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
          }
          //----------------- CRAFTING RECIPE 2 -----------------//
          else if(userCraftB == "2")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Apprentice Bait\n";
            cout<<"A leg up from a bucket of minnows to an assortment of somewhat appealing fish.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Shrimp x 5]\n[Carp x 3]\n[Small Mouth Bass x 1]\n[Large Mouth Bass x 1]\n\n";
            cout<<"Enter the number of Apprentice Baits you want to craft OR E to exit ---->  ";

            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;     
                
            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((fish[2] >= (5*craftConfirm)) && (fish[4] >= (3*craftConfirm)) && (fish[5] >= (1*craftConfirm)) && (fish[6] >= (1*craftConfirm))  )
            {
              cout << "Crafted " << craftConfirm << " Apprentice Bait";
              baitInventory[1] += craftConfirm;
              fish[2] -= 5*craftConfirm;
              fish[4] -= 3*craftConfirm;
              fish[5] -= 1*craftConfirm;         
              fish[6] -= 1*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do have enough resourses!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }       
          }
          //----------------- CRAFTING RECIPE 3 -----------------//
          else if(userCraftB == "3")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Chum\n";
            cout<<"A bucket full of foul smells that can bring anyone on their knees.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Pike x 9]\n[Zombie Fish x7]\n[Night Soul Fish]\n[Strange Flesh x 1]\n\n";
            cout<<"Enter the amount(units) of Chum you want to craft OR E to exit ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((fish[7] >= (9*craftConfirm)) && (fish[15] >= (7*craftConfirm)) && (fish[14] >= (7*craftConfirm)) && (miscInventory[3] >= (1*craftConfirm))  )
            {
              cout << "Crafted " << craftConfirm << " Chum";
              baitInventory[2] += craftConfirm;
              fish[7] -= 9*craftConfirm;
              fish[15] -= 7*craftConfirm;
              fish[14] -= 7*craftConfirm;         
              miscInventory[3] -= 1*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do have enough resourses!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
          }
          //----------------- CRAFTING RECIPE 4 -----------------//
          else if(userCraftB == "4")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Enchanted Bait\n";
            cout<<"A shiny and glossy bait that exudes magic.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Pixie Dust x 1]\n[Prismite x 5]\n[Neon Tetra x 2]\n[Rainbow Trout x 4]\n\n";
            cout<<"Enter the number of Enchanted Baits you want to craft OR E to exit ---->  ";

            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((miscInventory[2] >= (1*craftConfirm)) && (fish[11] >= (5*craftConfirm)) && (fish[10] >= (2*craftConfirm)) && (fish[9] >= (4*craftConfirm))  )
            {
              cout << "Crafted " << craftConfirm << " Enchanted Bait";
              baitInventory[3] += craftConfirm;
              miscInventory[2] -= 1*craftConfirm;
              fish[11] -= 5*craftConfirm;
              fish[10] -= 2*craftConfirm;         
              fish[9] -= 4*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do not have enough resources!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }      
          }
          //----------------- CRAFTING RECIPE 5 -----------------//
          else if(userCraftB == "5")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"High Quality Bait\n";
            cout<<"A selection of the finest fishes in the seas, even you could eat it!\n";
            cout<<"Recipe";
            cout<<"\n[Marlin x 1]\n[Seabass x 10]\n[Bluefin Tuna x 5]\n[Atlantic Cod x 3]\n[Bucket x 1]\n\n";
            cout<<"Enter the number of High Quality Baits you want to craft OR E to exit ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }        
            else if ((fish[18] >= (1*craftConfirm)) && (fish[8] >= (10*craftConfirm)) && (fish[12] >= (5*craftConfirm)) && (fish[13] >= (3*craftConfirm)) && (miscInventory[0] >= (1*craftConfirm)))
            {
              cout << "Crafted " << craftConfirm << " High Quality Bait(s)";
              baitInventory[4] += craftConfirm;
              fish[18] -= 1*craftConfirm;
              fish[8] -= 10*craftConfirm;         
              fish[12] -= 5*craftConfirm;
              fish[13] -= 3*craftConfirm;
              miscInventory[0] -= 1*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do not have enough resources!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
          }
          //----------------- CRAFTING RECIPE 6 -----------------//
          else if(userCraftB == "6")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Tourtrued Soul\n";
            cout<<"An unknown soul that has been trapped for god knows how long.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Soul Case x 1]\n[Zombie Fish x 15]\n[Night Soul Fish x 15]\n[Hagfish x 10]\n\n";
            cout<<"Enter the number of Tourtured Soul you want to craft OR E to exit ---->  ";

            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((miscInventory[1] >= (1*craftConfirm)) && (fish[15] >= (15*craftConfirm)) && (fish[14] >= (15*craftConfirm)) && (fish[17] >= (10*craftConfirm))  )
            {
              cout << "Crafted " << craftConfirm << " Tourtured Soul";
              miscInventory[4] += craftConfirm;
              miscInventory[1] -= 1*craftConfirm;
              fish[15] -= 15*craftConfirm;
              fish[14] -= 15*craftConfirm;         
              fish[17] -= 10*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do not have enough resources!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
          }
          //----------------- CRAFTING RECIPE 7 -----------------//
          else if(userCraftB == "7")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Ectoplasm\n";
            cout<<"A strange, white, ethereal substance left from ghosts when destroyed\n";
            cout<<"Recipe--> ";
            cout<<"\n[Pixie Dust x 2]\n[Ghost Fish x 10]\n[Zombie Fish x 6]\n[Night Soul Fish x 3]\n[Sun Fish x8]\n\n";
            cout<<"Enter the amount (units) of Ectoplasm you want to craft OR E to exit ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((miscInventory[2] >= (2*craftConfirm)) && (fish[16] >= (10*craftConfirm)) && (fish[15] >= (6*craftConfirm)) && (fish[14] >= (3*craftConfirm)) && (fish[3] >= (8*craftConfirm)))
            {
              cout << "Crafted " << craftConfirm << " Ectoplasm";
              miscInventory[5] += craftConfirm;
              miscInventory[2] -= 2*craftConfirm;
              fish[16] -= 10*craftConfirm;         
              fish[15] -= 6*craftConfirm;
              fish[14] -= 3*craftConfirm;
              fish[3] -= 8*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do not have enough resources!";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
          }
          //----------------- CRAFTING RECIPE 8 -----------------//
          else if(userCraftB == "8")
          {
          cout << "\033[2J\033[0;0H";
          cout<<"Radioactive Plating\n";
          cout<<"These plates are able to effectively absorb all types of radiation, preventing unnecessary breakdown of tools and equipment.\n";
          cout<<"Recipe--> ";
          cout<<"\n[Buckets x 20]\n[Prismite x 10]\n[Zombie Fish x 5]\n[Hagfish x 1]\n[Bluefin Tuna x 1]\n\n";
          cout<<"Enter the number of Radioactive Plating you want to craft OR E to exit ---->  ";
          cin>>craftConfirmA;
          craftConfirm = craftConfirmA;
          craftConfirm -= 48;
          
          if (craftConfirmA == 'E')
          {
            cout<<"Exited\n";
            userCraft = 1;              
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "\n";
          }
          
          else if ((miscInventory[0] >= (20*craftConfirm)) && (fish[11] >= (10*craftConfirm)) && (fish[15] >= (5*craftConfirm)) && (fish[17] >= (1*craftConfirm)) && (fish[12] >= (1*craftConfirm)) )
          {
            cout << "Crafted " << craftConfirm << " Radioactive Plating";
            miscInventory[8] += craftConfirm;
            miscInventory[0] -= 20*craftConfirm;
            fish[11] -= 10*craftConfirm;
            fish[15] -= 5*craftConfirm;         
            fish[17] -= 1*craftConfirm;
            fish[12] -= 1*craftConfirm;              
            cout<<"\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "\n";
          }
          else
          {
            cout<<"You do not have enough resources!";
            userCraft = 1;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "\n";
          }
          //break;
          }
          //----------------- CRAFTING RECIPE 9 -----------------//
          else if(userCraftB == "9")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Power Dampener\n";
            cout<<"Used to limit the amount of power a machine or tool exerts.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Tourted Soul x 1]\n[Ectoplasm x 1]\n[Radioactive Plating x 1]\n\n";
            cout<<"Enter the number of Power Dampeners you want to craft OR E to exit ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            craftConfirm -= 48;

            if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              userCraft = 1;              
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else if ((miscInventory[4] >= (1*craftConfirm)) && (miscInventory[5] >= (1*craftConfirm)) && (miscInventory[6] >= (1*craftConfirm)))
            {
              cout << "Crafted " << craftConfirm << " Power Dampener(s)";
              miscInventory[7] += craftConfirm;
              miscInventory[4] -= 1*craftConfirm;
              miscInventory[5] -= 1*craftConfirm;
              miscInventory[6] -= 1*craftConfirm;
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }
            else
            {
              cout<<"You do not have enough resources";
              userCraft = 1;
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }    
          }
          //----------------- CRAFTING RECIPE 10 -----------------//
          //Same applies for recipes 11-13
          else if(userCraftB == "10")
          {
            //Displays info about rod, but they can only craft one at a time
            cout << "\033[2J\033[0;0H";
            cout<<"Lead Rod\n";
            cout<<"A reinforced rod layered in radioactive shielding for toxic environments.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Radioactive Plating x 2]\n[Reinforced Fishing Pole]\n\n";
            cout<<"Enter X to Forge ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            
            //If they choose to forge
            if(craftConfirmA == 'X')
            {
              craftConfirm =1;
              //If they can craft the rod
              if ((miscInventory[6] >= (2*craftConfirm)) && (rodInventory[1] >= (1*craftConfirm))  )
              {
                //Tell user they crafted the rod 
                cout << "You have crafted the Lead Rod!";
                rodInventory[3] += craftConfirm;
                miscInventory[6] -= 2*craftConfirm;
                rodInventory[1] -= 1*craftConfirm;           
                cout<<"\n";
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "\n";
              }
              //Else tell them they do not have enough resources
              else
              {
                cout<<"You do not have enough resources!\n";
                userCraft = 1;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "\n";
              }
            }

            else if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }      
            else
            {
              cout<<"not a valid input\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";                  
            }
          }
          //----------------- CRAFTING RECIPE 11 -----------------//
          else if(userCraftB == "11")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Lucifier's Cast\n";
            cout<<"A rod forged from tortured souls and suffering.\n";
            cout<<"Recipe--> ";
            cout<<"\n[Prismite x 1]\n[Tortured Souls x 6]\n[Reinforced Fishing Pole]\n\n";
            //cin>>craftConfirm;
            cout<<"Enter X to Forge ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            
            if(craftConfirmA == 'X')
            {
              craftConfirm = 1;
              if ((fish[11] >= (1*craftConfirm)) && (miscInventory[4] >= (6*craftConfirm)) && (rodInventory[1] >= (1*craftConfirm)))
              {
                cout << "You have crafted Lucifer's Cast!";
                rodInventory[4] += craftConfirm;
                fish[11] -= 1*craftConfirm;
                miscInventory[4] -= 6*craftConfirm;
                rodInventory[1] -= 1*craftConfirm;
                cout<<"\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
                cout << "\n";
              }
              else
              {
                cout<<"You do not have enough resources!\n";
                userCraft = 1;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "\n";
              }
            }

            else if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }           
            else
            {
              cout<<"not a valid input\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";   
            }
          }
          //----------------- CRAFTING RECIPE 12 -----------------//
          else if(userCraftB == "12")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Ghost Reeler\n";
            cout<<"A phantom rod used that is nimble and can detect elusive phantom fish.\n";
            cout<<"Recipe--> ";
            cout<<"[Ectoplasm x 17]\n[Fiberglass Fishing Pole]\n\n";
            cout<<"Enter X to Forge ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            
            if(craftConfirmA == 'X')
            {
              craftConfirm = 1;
              if ((miscInventory[5] >= (17*craftConfirm)) && (rodInventory[2] >= (1*craftConfirm))  )
              {
                cout << "You have created the Ghost Reeler!";
                rodInventory[5] += craftConfirm;
                miscInventory[5] -= 17*craftConfirm;
                rodInventory[2] -= 1*craftConfirm;             
                cout<<"\n";
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "\n";
              }
              else
              {
                cout<<"You do not have enough resources!\n";
                userCraft = 1;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "\n";
              }
            }

            else if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }   
            else 
            {
              cout << "not a valid input!\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";   
            }        
          }
          //----------------- CRAFTING RECIPE 13 -----------------//
          else if(userCraftB == "13")
          {
            cout << "\033[2J\033[0;0H";
            cout<<"Neagtive Rod\n";
            cout<<"This rod has been diminished beyond even the Starter Rod’s capabilities.\n";
            cout<<"Recipe--> ";
            cout<<"[Power Dampener x 1]\n[Starter Rod]\n\n";
            //cin>>craftConfirm;

            cout<<"Enter X to Forge ---->  ";
            cin>>craftConfirmA;
            craftConfirm = craftConfirmA;
            
            if(craftConfirmA == 'X')
            {
              craftConfirm = 1;
              if ((miscInventory[7] >= (1*craftConfirm)) && (rodInventory[0] >= (1*craftConfirm)))               
              {                 
                cout << "You have crafted the Negative Rod!";      
                rodInventory[6] += craftConfirm;     
                miscInventory[7] -= 1*craftConfirm;   
                rodInventory[0] -= 1*craftConfirm;           
                cout<<"\n";      
                this_thread::sleep_for(chrono::milliseconds(3000));       
                cout << "\n";               
              }               
              else               
              {                 
                cout<<"You do not have enough resources!\n";                 
                userCraft = 1;                 
                this_thread::sleep_for(chrono::milliseconds(1000));                
                cout << "\n";               
              }
            }

            //If the user chooses to exit instead of crafting
            else if (craftConfirmA == 'E')
            {
              cout<<"Exited\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";
            }    
            //If the user inputs an invalid input
            else
            {
              cout<<"not a valid input\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout << "\n";                
            }     
          }
          //----------------- WHEN EXITING CRAFT MENU -----------------//
          else if(userCraftB == "E")
          {
            cout<<"Successfully Exited!\n";
            userCraftB = "E";
            this_thread::sleep_for(chrono::milliseconds(1000));
            option = "I";            
          }
          //----------------- DEFAULTING -----------------//
          //Clears screen and returns to craft menu
          cout << "\033[2J\033[0;0H";
          option = "I";       
        }
      }
      //Returns to menu
      else if (option == "E")
      {
        //Runs the menu function to return to menu
        cout << "\033[2J\033[0;0H";
        menu(fish, dailyFish, rodTypes, baitTypes, rodInventory, baitInventory, miscInventory, purse, lifetimeFish, totalDays);
      }
      //User chooses the use command
      else if (option == "U")
      {
        //Loops while the option is not I (keeps it in the use menu)
        while (option != "I")
        {
          //Displays options
          cout << "\033[2J\033[0;0H";
          cout<<"R - Rods\n";
          cout<<"B - Bait\n";
          cin>>option;

          //If the user chooses to use a Rod
          if (option=="R")
          {
            //Declaring and restating variables
            rodNum = 0;
            char rodChar;
            int j = 0;
            cout << "\033[2J\033[0;0H";
            //While the rod chosen is less than 20 (valid input)
            while (rodNum < 20)
            {
              //Loops 7 times
              for (i=0;i<7;i++)
              {
                //Displays all types of rods
                cout << i + 1<< ". " << rodNames[i] << "\n";
              }
              //Asks user for command
              cin>>rodChar;
              rodNum = rodChar;
              rodNum -= 48;
              //If the user enters E
              if (rodNum > 20)
              {
                //Shows that it exited
                cout<<"exited";
              }
              //Else the user selects a rod
              else
              {
                //Checks if the user has that rod
                if (rodInventory[rodNum-1] > 0 )
                {
                  //Resets all rodsTypes to 0 (meaning no rod is selected)
                  //int rodTypes[7] = {0,0,0,0,0,0,0};
                  //Loops 7 times
                  for(j=0;j<7;j++)
                  {
                    //Resets all rodTypes to 0
                    rodTypes[j] = 0;
                  }
                  //Sets choosen rodType to 1 (meaning it is the rod selected and used)
                  rodTypes[rodNum - 1] = 1;
                  //Displays that that rod has been chosen
                  cout << rodNames[rodNum-1] << " has been chosen!\n";
                  cout<<"\n";
                  this_thread::sleep_for(chrono::milliseconds(1000));
                  cout<<"\n";
                  cout << "\033[2J\033[0;0H";
                }
                //If the rod the user selected is not owned by the user
                else if (rodInventory[rodNum-1] == 0)
                {
                  //Tell them they do not own that rod
                  cout << "You do not own the " << rodNames[rodNum-1] << " rod!";
                  cout<<"\n";
                  this_thread::sleep_for(chrono::milliseconds(1000));
                  cout<<"\n";
                  cout << "\033[2J\033[0;0H";
                }
              }
            }
          }
          //If the user chooses to select a bait
          else if (option == "B")
          {
            //Declaring and restating variables
            baitNum = 0;
            char baitChar;
            int j = 0;
            cout << "\033[2J\033[0;0H";
            //While the bait chosen is less than 20 (valid input)
            while (baitNum < 20)
            {
              //Loops 5 times
              for (i=0; i<5; i++)
              {
                //Displays all bait types
                cout << i +1 << ". " << baitNames[i] << "\n";
              }
              //Asks user for command
              cin >> baitChar;
              baitNum = baitChar;
              baitNum -=48;
              //If the user enters E
              if (baitNum > 20)
              {
                //Shows that it exited
                cout<<"exited";
              }
              //baitNum = baitChar;
              //Else the user selects a bait
              else
              {
                //Checks if the user has that bait
                if (baitInventory[baitNum-1] > 0)
                {
                  //int baitTypes[5] = {0, 0, 0, 0, 0};
                  //Loops 5 times
                  for(j=0;j<5;j++)
                  {
                    //Resets all baitTypes to 0
                    baitTypes[j] = 0;
                  }
                  //Sets choosen baitType to 1 (meaning it is the bait selected and used)
                  baitTypes[baitNum - 1] = 1;
                  //Subtracts 1 bait from their inventory since they used it
                  baitInventory[baitNum - 1] --;
                  //Displays that the bait has been chosen
                  cout << baitNames[baitNum-1] << " has been chosen!\n";
                  cout<<"\n";
                  this_thread::sleep_for(chrono::milliseconds(1000));
                  cout<<"\n";
                  cout << "\033[2J\033[0;0H";
                }
                //Else they do not own the bait they selected
                else if (baitInventory[baitNum-1] < 1)
                {
                  //Tells the user that they do not own that bait
                  cout << "You do not own the " << baitNames[baitNum-1] << " bait!";
                  cout<<"\n";
                  this_thread::sleep_for(chrono::milliseconds(1000));
                  cout<<"\n";
                  cout << "\033[2J\033[0;0H";
                }
              }
            }
          }
          //If the user wants to exit
          else if (option == "E" )
          {
            //Exit out to the Inventory
            //cout<<"test\n";
            cout << "\033[2J\033[0;0H";
            option = "I";
          }
        }
      }
      //
      else if (option == "S")
      {
        while (option != "I")
        {
          cout << "\033[2J\033[0;0H";
          for (i=0;i<25;i++)
          {
            if (fish[i] > 0)
            {
              cout << i+1 << ". ";
              cout<<fishName[i];
              cout << " - ";
              cout<<itemValue[i];
              cout<<"\n";
            }
            else
            {
              //Combine couts to make less lines
              cout << i+1 << ". ";
              fishName[i].assign(10, '?');
              cout<<fishName[i];
              cout<<"\n";
            }
          }
          cout<<"\n Which fish would you like to sell";
          
          cin>>sellString;  
          
          
          if (sellString == "E")
          {
            cout << "\033[2J\033[0;0H";
            option = "I";
          }
          
          else 
          {
            stringstream newVarName;
            newVarName << sellString;
            newVarName>>sellNum;     
                   
          if (sellNum <= 25)
          {
            //sellNum = sellChar;
            cout<<"\n" <<fishName[sellNum-1] << "\n";
            cout << "How many of this fish would you like to sell?\n";
            cin>>sellAmount;
            if (fish[sellNum-1] >= sellAmount)
            {
              purse += (sellAmount * itemValue[sellNum-1]);
              fish[sellNum-1] -= sellAmount;
              cout<<"sold " << sellAmount << " " << fishName[sellNum-1]<<" (s)" << "for " << sellAmount * itemValue[sellNum-1];
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout<<"\n";
            }
            else 
            {
              cout << "You cannot sell this amount of this fish!";
              cout<<"\n";
              this_thread::sleep_for(chrono::milliseconds(1000));
              cout<<"\n";
            }
          }
          
          else 
          {
            cout << "This fish does not exist!";
            cout<<"\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout<<"\n";
          }
          }
        }
      }
    }
  }
  else if (option == "S")
  {
    while (shopString != "E")
    {
      cout << "\033[2J\033[0;0H";
      for(i = 0; i < 7; i++)
      {
        cout << i + 1 << ". " << shopNames[i] << shopValue[i] << "\n";
      }
      cout << "What item would you like to buy? \n";
      cin >> shopString;

      if (shopString == "E")
      {
        cout << "\033[2J\033[0;0H";
        menu(fish, dailyFish, rodTypes, baitTypes, rodInventory, baitInventory, miscInventory, purse, lifetimeFish, totalDays);
      }
      else
      {
        stringstream newVarName;
        newVarName << shopString;
        newVarName>>shopNum;
      }
      
      if (shopNum < 8)
      {
        if(purse >= shopValue[shopNum -1])
        {
          if (shopNum <= 4)
          {
            miscInventory[shopNum-1] ++;
            purse -= shopValue[shopNum-1];
          }
          else
          {
            rodInventory[shopNum-5] ++;
            purse -= shopValue[shopNum-1];
          }
          cout << "You have purchased the " << shopNames[shopNum-1] << "!";
          cout<<"\nPurse - $" << purse;
          cout<<"\n";
          this_thread::sleep_for(chrono::milliseconds(2000));
          cout<<"\n";
        }
        else if (purse < shopValue[shopNum -1])
        {
          cout << "you dont have enough money";
          cout<<"\n";
          this_thread::sleep_for(chrono::milliseconds(1000));
          cout<<"\n";
        }
      }
      else
      {
        cout<<"not a valid imput";
        cout<<"\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout<<"\n";      
      }
    }
  }
  else if (option == "B")
  {
    cout << "\033[2J\033[0;0H";
    while (beastString != "E")
    {
      cout << "\033[2J\033[0;0H";
      exitDesc = "DEFUALT";
      while ((exitDesc != "E") && (beastString != "E"))
      {//while loop bracket
        int y = 0;
        int j = 0;
        //i =1; i < 26
        for (i=0;i<25;i++)
        {
          //Change to lifetimeFish[i] later
          //i-1
          if (lifetimeFish[i] > 0)
          {
            for (y=1;y<26;y++)
            {
              length = beastName[y-1].length();
              for (j=length;j<25;j++)
              {
                beastName[y-1] = beastName[y-1] + " ";
              }
            }
            //Temp for printf
            if ((i+1) < 10)
            {
              cout << (i+1) << " . ";
            }
            else
            {
              cout << (i+1) << ". ";
            }
            cout<<beastName[i];
            cout<<"\t";
          }
          else
          {
            //Temp for printf
            if ((i+1) < 10)
            {
            cout << (i+1) << " . ";
            }
            else
            {
            cout << (i+1) << ". ";
            }
            beastName[i].assign(10, '?');
            for (y=1;y<26;y++)
            {
              length = beastName[y-1].length();
              for (j=length;j<25;j++)
              {
                beastName[y-1] = beastName[y-1] + " ";
              }
            }
            cout<<beastName[i];
            cout<<"\t";
          }
          
          if ((i+1)%5 == 0)
          {
            cout<<"\n";
          }
        }

          percentFish = 0;
        for(i=0;i<25;i++)
        {
          if(lifetimeFish[i] > 0)
          {
            percentFish++;
          }
        } 
        cout << "\n";
        cout << percentFish*4 << "%";
        cout << "\n";

        cin>>beastString;
        if (beastString == "E")
        {

        }
        else
        {
          stringstream newVarName;
          newVarName << beastString;
          newVarName>>beastNum;
        
          cout << "\033[2J\033[0;0H";
          cout<<"/-------------------/\n";
          cout<<fishName[beastNum-1];
          cout<<"\n\nLifeTime Catches - " << lifetimeFish[beastNum-1];
          cout<<"\n";
          cout<<fishDesc[beastNum-1];
          cin>>exitDesc;
          if(exitDesc == "E")
          {
            //NOTHING
          }
        }
      }//while loop bracket
    }
      cout << "\033[2J\033[0;0H";
      menu(fish, dailyFish, rodTypes, baitTypes, rodInventory, baitInventory, miscInventory, purse, lifetimeFish, totalDays);
  }
  else if (option == "L")
  {

  }
}

























void tenA (int fish[25], int dailyFish[25], int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather)
{
  //Setting the random seed for the random number generated
  srand((int)time(0));

  //Declaring variables that are used in function
  int randNum = 0;
  int i=0;
  int time = 10;
  int y = 0;
  int animation = 0;
  int rainRandNum;
  int rainPower = 0;
    
  if (rainLength > 0) 
  {
    rainLength--;
    rainPower = 90;
  }
  else
  {
    rainRandNum = rand() % 1 + 1;

    if (rainRandNum == 1)
    {
      //rainLength = rand() % 3 + 1;
      rainLength = 2;
      rainPower = 90;
      weather = "rainy";
    }
    else
    {
      weather = "Clear Skys";
    }
  }



  //Looping 10 times during this time period and every second checks if a fish is caught
  for (i=0;i<10;i++)
  {
    //this_thread::sleep_for(chrono::milliseconds(500));
    //Displays the fishing animation by calling to screen function
    screen(animation,time, weather);
    //------------------------------------//
    //Generates random number to see if a fish is caught
    randNum = rand() % (100 - rodPower - rainPower) ;
    //If the random number is 0
    //Should be 10 normally

    //If a fish is caught
    if (randNum < 10)
    {
      //Generate another random number
      //randNum = rand() % [100+30-15] + 15;

      //Generate another random number to see what fish is caught 
      randNum = rand() % (100-baitPower - rainPower) + (1+baitPower + rainPower);

      //Depending on the random number, decides which fish was caught
      if (randNum <= 20)
      {
        //Outputs the fish that was caught
        cout << "Boot\n";
        //Adds a fish to the total amount of that fish
        dailyFish[0]++;
      }
      else if (randNum > 20 && randNum <= 75)
      {
        cout << "Minnow\n";
        dailyFish[1]++;
      }
      else if (randNum > 75 && randNum <= 100)
      {
        cout << "Shrimp\n";
        dailyFish[2]++;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(times));
    cout<<"\n";

  }
}





















void elevenA (int fish[25], int dailyFish[25], int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather)
{
  //Setting the random seed for the random number generated
  srand((int)time(0));

  //Declaring variables that are used in function
  int randNum = 0;
  int i=0;
  int time = 11;
  int y = 0;
  int animation = 0;



  int rainRandNum;
  int rainPower = 0;
    
  if (rainLength > 0) 
  {
    rainLength--;
    rainPower = 90;
  }
  else
  {
    rainRandNum = rand() % 2 + 1;

    if (rainRandNum == 1)
    {
      //rainLength = rand() % 3 + 1;
      rainLength = 3;
      rainPower = 90;
            weather = "rainy";
    }
    else
    {
      weather = "Clear Skys";
    }
  }



  //Looping 10 times during this time period and every second checks if a fish is caught
  for (i=0;i<10;i++)
  {
    //this_thread::sleep_for(chrono::milliseconds(500));
    //Displays the fishing animation by calling to screen function
    screen(animation,time, weather);
    //------------------------------------//
    //Generates random number to see if a fish is caught
    randNum = rand() % (100 - rodPower - rainPower) ;
    //If the random number is 0
    //Should be 10 normally

    //If a fish is caught
    if (randNum < 10)
    {
      //Generate another random number
      //randNum = rand() % [100+30-15] + 15;

      //Generate another random number to see what fish is caught 
      randNum = rand() % (100-baitPower - rainPower) + (1+baitPower + rainPower);

      //Depending on the random number, decides which fish was caught
      if (randNum <= 20)
      {
        //Outputs the fish that was caught
        cout << "Boot\n";
        //Adds a fish to the total amount of that fish
        dailyFish[0]++;
      }
      else if (randNum > 20 && randNum <= 75)
      {
        cout << "Minnow\n";
        dailyFish[1]++;
      }
      else if (randNum > 75 && randNum <= 100)
      {
        cout << "Shrimp\n";
        dailyFish[2]++;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(times));
    cout<<"\n";

  }
}














void twelveP (int fish[25], int dailyFish[25], int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather)
{
  //Setting the random seed for the random number generated
  srand((int)time(0));

  //Declaring variables that are used in function
  int randNum = 0;
  int i=0;
  int time = 12;
  int y = 0;
  int animation = 0;


  int rainRandNum;
  int rainPower = 0;
    
  if (rainLength > 0) 
  {
    rainLength--;
    rainPower = 90;
  }
  else
  {
    rainRandNum = rand() % 2 + 1;

    if (rainRandNum == 1)
    {
      //rainLength = rand() % 3 + 1;
      rainLength = 3;
      rainPower = 90;
      weather = "rainy";
    }
    else
    {
      weather = "Clear Skys";
    }
  }

  
  //Looping 10 times during this time period and every second checks if a fish is caught
  for (i=0;i<10;i++)
  {
    //this_thread::sleep_for(chrono::milliseconds(500));
    //Displays the fishing animation by calling to screen function
    screen(animation,time, weather);
    //------------------------------------//
    //Generates random number to see if a fish is caught
    randNum = rand() % (100 - rodPower - rainPower) ;
    //If the random number is 0
    //Should be 10 normally

    //If a fish is caught
    if (randNum < 10)
    {
      //Generate another random number
      //randNum = rand() % [100+30-15] + 15;

      //Generate another random number to see what fish is caught 
      randNum = rand() % (100-baitPower - rainPower) + (1+baitPower + rainPower);

      //Depending on the random number, decides which fish was caught
      if (randNum <= 20)
      {
        //Outputs the fish that was caught
        cout << "Boot\n";
        //Adds a fish to the total amount of that fish
        dailyFish[0]++;
      }
      else if (randNum > 20 && randNum <= 75)
      {
        cout << "Minnow\n";
        dailyFish[1]++;
      }
      else if (randNum > 75 && randNum <= 100)
      {
        cout << "Shrimp\n";
        dailyFish[2]++;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(times));
    cout<<"\n";

  }
}
















void oneP (int fish[25], int dailyFish[25], int& rodPower, int& baitPower, int& rainCheck, int& rainLength, string& weather)
{
  //Setting the random seed for the random number generated
  srand((int)time(0));

  //Declaring variables that are used in function
  int randNum = 0;
  int i=0;
  int time = 1;
  int y = 0;
  int animation = 0;

  
  int rainRandNum;
  int rainPower = 0;
    
  if (rainLength > 0) 
  {
    rainLength--;
    rainPower = 90;
  }
  else
  {
    rainRandNum = rand() % 100 + 1;

    if (rainRandNum == 1)
    {
      //rainLength = rand() % 3 + 1;
      rainLength = 3;
      rainPower = 90;
      weather = "rainy";
    }
    else
    {
      weather = "Clear Skys";
    }
  }



  //Looping 10 times during this time period and every second checks if a fish is caught
  for (i=0;i<10;i++)
  {
    //this_thread::sleep_for(chrono::milliseconds(500));
    //Displays the fishing animation by calling to screen function
    screen(animation,time, weather);
    //------------------------------------//
    //Generates random number to see if a fish is caught
    randNum = rand() % (100 - rodPower - rainPower) ;
    //If the random number is 0
    //Should be 10 normally

    //If a fish is caught
    if (randNum < 10)
    {
      //Generate another random number
      //randNum = rand() % [100+30-15] + 15;

      //Generate another random number to see what fish is caught 
      randNum = rand() % (100-baitPower - rainPower) + (1+baitPower + rainPower);

      //Depending on the random number, decides which fish was caught
      if (randNum <= 20)
      {
        //Outputs the fish that was caught
        cout << "Boot\n";
        //Adds a fish to the total amount of that fish
        dailyFish[0]++;
      }
      else if (randNum > 20 && randNum <= 75)
      {
        cout << "Minnow\n";
        dailyFish[1]++;
      }
      else if (randNum > 75 && randNum <= 100)
      {
        cout << "Shrimp\n";
        dailyFish[2]++;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(times));
    cout<<"\n";

  }
}
