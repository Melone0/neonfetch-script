#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unistd.h>
#include <cstring>
using namespace std;

// Paste your bashrc Path here (usual in your home)
string bashrc_path = " ";
// *******************^********



void clean_line()
{
    std::fstream file(bashrc_path.c_str(), std::ios::in);

if(file.is_open()) {
    std::string replace = "neofetch";
    std::string replace_with = "";
    std::string line;
    std::vector<std::string> lines;
    
    while(std::getline(file, line)) {
        
        std::string::size_type pos = 0;
        
        while ((pos = line.find(replace, pos)) != std::string::npos){
            line.replace(pos, line.size(), replace_with);
            pos += replace_with.size();
        }
        
        lines.push_back(line);
    }

    file.close();
    file.open(bashrc_path.c_str(), std::ios::out | std::ios::trunc);
    
    for(const auto& i : lines) {
        file << i << std::endl;
    }
}
else{
    cout << "failed to open the file";
}
}

int mew_start()
{
    string line;
    vector<string> lines;
    const int line_number = 2;
    string mew = "neofetch --colors 5 5 7 5 5 7  --kitty nf-profile/nf-profile-pictures/Mew.png";
    fstream read_myfile;
    read_myfile.open (bashrc_path.c_str());
    if(read_myfile.fail()){
        cout << "failes to open fail" << endl;
    }

        
        while(getline(read_myfile, line))
            lines.push_back(line);

            read_myfile.close();

     if (line_number > lines.size())
  {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }

            ofstream write_myfile;
            write_myfile.open (bashrc_path.c_str());
            if(write_myfile.is_open())
            {

            for (int i = 0; i < lines.size(); i++)
            {
                if (i != line_number)
                    write_myfile << lines[i] << endl;

                else
                    write_myfile << mew << endl;

            }
            }
 write_myfile.close();
                    return 0;

}


int sonic_start()
{
    string line;
    vector<string> lines;
    const int line_number = 2;
    string sonic = "neofetch --colors 8 1 8 7 7 1 --kitty nf-profile/nf-profile-pictures/sonic.png";
    fstream read_myfile;
    read_myfile.open (bashrc_path.c_str());
    if(read_myfile.fail()){
        cout << "failes to open fail";
    }

        
        while(getline(read_myfile, line))
            lines.push_back(line);
            cout << lines.size();

            read_myfile.close();

     if (line_number > lines.size())
  {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }

            ofstream write_myfile;
            write_myfile.open (bashrc_path.c_str());
            if(write_myfile.is_open())
            {

            for (int i = 0; i < lines.size(); i++)
            {
                if (i != line_number)
                    write_myfile << lines[i] << endl;

                else
                    write_myfile << sonic << endl;

            }
            }
 write_myfile.close();
                    return 0;

}

void help()
{
    cout << "**********This is help of nf-script**********";
    cout << endl;
    cout << "On the First start use -c to Clear the .bashrc config (just the word neofetch)" << endl;
    cout << endl;
    cout << "use -r to reload your Terminal" << endl;
    cout << endl;
    cout << "use -m for mew-profile" << endl;
    cout << "use -s for sonic-profile" << endl;
}

int main (int argc, char *argv[]) {
   int cl_input;
  opterr = 0;
  while ((cl_input = getopt(argc, argv, ":cmshr")) != -1)
    switch (cl_input)
      {
      case 'c':
        clean_line();
        break;
      case 's':
        sonic_start();
        break;

      case 'm':
        mew_start();
        break;

        case 'r':
        system("bash");
        break;

      case 'h':
        help();
        break;

      case '?':
        cout << "No valid argument , use -h";
        return 1;
      default:
        abort ();
}
}
