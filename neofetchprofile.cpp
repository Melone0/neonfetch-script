#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unistd.h>
using namespace std;



void clean_line()
{
    std::fstream file("/home/melone/.bashrc", std::ios::in);

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
    file.open("/home/melone/.bashrc", std::ios::out | std::ios::trunc);
    
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
    string mew = "neofetch --kitty /projekte/neofecht-script/nf-profile-pictures/Mew.png";
    fstream read_myfile;
    read_myfile.open ("/home/melone/.bashrc");
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
            write_myfile.open ("/home/melone/.bashrc");
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
    string sonic = "neofetch --kitty /projekte/neofecht-script/nf-profile-pictures/sonic.png";
    fstream read_myfile;
    read_myfile.open ("/home/melone/.bashrc");
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
            write_myfile.open ("/home/melone/.bashrc");
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
    cout << "On the First start use -c to Clear the .bashrc config" << endl;
    cout << endl;
    cout << "use -m for mew-profile" << endl;
    cout << "use -s for sonic-profile" << endl;
}

int main (int argc, char *argv[]) {
   int cl_input;
  opterr = 0;
  // Checking the file flag is specified
  while ((cl_input = getopt(argc, argv, ":cmsh")) != -1)
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