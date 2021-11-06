//imports libs
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//functions prototype
void configloader (int array1[], int array2[], int array3[]);
void storm (int array4[], int array5[], int array1[], int array3[]);
void burst (int array4[], int array6[], int array7[], int array1[]);
void windsim (int array4[], int array6[], int array8[], int array1[]);

//function configloader
void
configloader (int array1[], int array2[], int array3[])
{
  // create and open windspeeddata.txt to store data in
  ofstream windspeed;
  windspeed.open ("WindSpeedData.txt", ios::out);

  //check file opening
  if (windspeed.fail ())
    {
      cerr << "opening  file failed \n";
      exit (0);
    }
  int array4[array1[2]];

  //store data in file
  windspeed << left << setw (10) << "duration" << left << setw (10) <<
    "windspeed" << endl;
  srand (static_cast < unsigned int >(time (nullptr)));
  for (int x = 0; x <= array1[2]; x += array1[3])
    {

      int randomwind =
    rand () % (((array1[0] + array1[1]) - (array1[0] - array1[1])) + 1) +
    (array1[0] - array1[1]);
      windspeed << left << setw (10) << x << left << setw (10) << randomwind
    << endl;
      array4[x] = randomwind;

    }
  storm (array4, array2, array1, array3);

  //close file
  windspeed.close ();
}

//function storm
void
storm (int array4[], int array7[], int array1[], int array3[])
{
  srand (static_cast < unsigned int >(time (nullptr)));

  //create and read stormdata.txt
  ofstream stormdata;
  stormdata.open ("StormData.txt", ios::out);

  //check file opening
  if (stormdata.fail ())
    {
      cerr << "opening  file failed \n";
      exit (0);
    }

  //declaring variables
  float newspeed;
  float Prand = (rand () % 100);
  Prand = Prand / 100;
  float probability = array7[0];
  float prob = probability / 100;
  int x = 0;
  int array6[array1[2]];

  //write data in file if it passed true the conditions
  stormdata << left << setw (10) << "duration" << left << setw (10) <<
    "windspeed" << endl;

  //generate random value

  for (int y; y <= array1[2]; y += array1[3])
    {
      float randomstorm = array7[1] + rand () % ((array7[2] - array7[1] + 1));
      float T = array7[3] + rand () % ((array7[4] - array7[3] + 1));
      float newtime = T + x;

      if (Prand <= prob)
    {
      for (x; x <= newtime && x <= array1[2]; x += array1[3])
        {
          newspeed = randomstorm + array4[x];
          stormdata << left << setw (10) << x << left << setw (10) <<
        newspeed << endl;
          array6[x] = newspeed;
        }
    }
      else
    {
      stormdata << left << setw (10) << x << left << setw (10) <<
        array4[x] << endl;
      array6[x] = array4[x];
      x += array1[3];
    }

      Prand = (rand () % 100);
      Prand = Prand / 100;

    }
  burst (array4, array6, array3, array1);

  //close the file
  stormdata.close ();
}

//function burst
void
burst (int array4[], int array6[], int array7[], int array1[])
{
  srand (static_cast < unsigned int >(time (nullptr)));
  bool isStorm;

  //create filestream and open burstdata.txt
  ofstream burstdata;
  burstdata.open ("BurstData.txt", ios::out);

  //check file opening
  if (burstdata.fail ())
    {
      cerr << "opening  file failed \n";
      exit (0);
    }

  //declaring variables
  float newspeed, Prand = (rand () % 100);
  Prand = Prand / 100;
  float probability = array7[0];
  float prob = probability / 100;
  int array8[array1[2]];
  int x = 0;

  //write data in file if it passed true the conditions
  burstdata << left << setw (10) << "duration" << left << setw (10) <<
    "windspeed" << endl;

  //generate random value

  for (int y; y <= array1[2]; y += array1[3])

    {
      float randomburst = array7[1] + rand () % ((array7[2] - array7[1] + 1));
      float T = array7[3] + rand () % ((array7[4] - array7[3] + 1));
      float bursttime = T + x;
      if (array6[x] > array4[x])
    {
      isStorm = true;
    }
      else
    {
      isStorm = false;
    }
      if (Prand <= prob)
    {

      for (x; isStorm == true && x <= bursttime; x += array1[3])
        {
          newspeed = randomburst + array6[x];
          burstdata << left << setw (10) << x << left << setw (10) <<
        newspeed << endl;
          array8[x] = newspeed;
        }
    }
      else
    {
      burstdata << left << setw (10) << x << left << setw (10) <<
        array6[x] << endl;
      array8[x] = array6[x];
      x += array1[3];
    }

      Prand = (rand () % 100);
      Prand = Prand / 100;

    }
  windsim (array4, array6, array8, array1);

  //close the file
  burstdata.close ();
}

  //function windsim
void
windsim (int array4[], int array6[], int array8[], int array1[])
{
  //create and open WindSimulation.txt
  ofstream windsimulation;
  windsimulation.open ("WindSimulation.txt", ios::out);

  //collecting values from the files and store data in file if it passed true
  windsimulation << left << setw (10) << "duration" << left << setw (10) <<
    "windspeed" << left << setw (12) << "stormspeed" << left << setw (10) <<
    "burstspeed" << endl;
  for (int x = 0; x <= array1[2]; x += array1[3])
    {
      windsimulation << left << setw (10) << x << left << setw (10) <<
    array4[x] << left << setw (12) << array6[x] << left << setw (10)
    << array8[x];
      if (array6[x] > array4[x])
    {

      windsimulation << left << setw (10) << "1" << endl;

    }
      else
    {
      windsimulation << endl;
    }
    }
  cout <<
    "Simulation of wind speed for a flight simulator created successfully" <<
    endl;
  //close the file
  windsimulation.close ();
}

//main function
int
main ()
{
  //open and read values from configFile
  ifstream conf;
  conf.open ("simulationConfiguration.txt", ios::in);

  //check file opening
  if (conf.fail ())
    {
      cerr << "open file failed \n";
      exit (0);
    }
  //store data of each line in array
  int array1[4], array2[5], array3[5];
  for (int x = 0; x < 4; x++)
    {
      conf >> array1[x];
    }
  for (int x = 0; x < 5; x++)
    {
      conf >> array2[x];
    }
  for (int x = 0; x < 5; x++)
    {
      conf >> array3[x];
    }

  configloader (array1, array2, array3);

  //close file
  conf.close ();
  return 0;
}
