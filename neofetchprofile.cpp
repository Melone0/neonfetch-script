#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unistd.h>
using namespace std;



void clean_line()
{
    std::fstream file("/home/melone/Dokumente/.bashtest", std::ios::in);

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
    file.open("/home/melone/Dokumente/.bashtest", std::ios::out | std::ios::trunc);
    
    for(const auto& i : lines) {
        file << i << std::endl;
    }
}
else{
    cout << "failed to open the file";
}
}

int test()
{
  string text = "neofetch --kitty /projekte/neofecht-script/Mew-Pokemon-PNG-Photo-Image.png";
  int line_number = 2;  
  fstream read_file;
  read_file.open("/home/melone/Dokumente/.bashtest");
  
  if (read_file.fail())
  {
   std::cout << "Error opening file." << endl;

    return 1;
  }
  
  vector<string> lines;
  string line;
  
  while (getline(read_file, line))
    lines.push_back(line);
  
  read_file.close();
  
  if (line_number > lines.size())
  {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }
  
  ofstream write_file;
  
  write_file.open("/home/melone/Dokumente/.bashtest");
  
  if (write_file.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }
  for (int i = 0; i < lines.size(); i++)
  {
    if (i != line_number)
      write_file << lines[i] << endl;
    else 
      write_file << text << endl; 
  }
  write_file.close();

  return 0;
}

int mew_start()
{
    string line;
    vector<string> lines;
    const int line_number = 2;
    string mew = "neofetch --kitty /projekte/neofecht-script/Mew-Pokemon-PNG-Photo-Image.png";
    fstream read_myfile;
    read_myfile.open ("/home/melone/Dokumente/.bashtest");
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
            write_myfile.open ("/home/melone/Dokumente/.bashtest");
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
    string sonic = "neofetch --kitty Downloads/imageedit_0_3056955705.png";
    fstream read_myfile;
    read_myfile.open ("/home/melone/Dokumente/.bashtest");
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
            write_myfile.open ("/home/melone/Dokumente/.bashtest");
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





int Open_and_Bufefer()
{
    string line;
    vector<string> lines;
    const int line_number = 2;
    string mew = "neofetch --kitty /projekte/neofecht-script/Mew-Pokemon-PNG-Photo-Image.png";
    fstream read_myfile;
    read_myfile.open ("/home/melone/Dokumente/.bashtest");
    
    if (!read_myfile.is_open())
    {
        cout << "file failed";
        return 1;
    }
    else {
    
    stringstream buffer;

    buffer << read_myfile.rdbuf();

    string file_content;

    file_content = buffer.str();

    read_myfile.close();

    cout << file_content[2];

    ofstream write_myfile;
    write_myfile.open("/home/melone/Dokumente/.bashtest");

    if (write_myfile.is_open())
    {
        for (int i = 0;i < file_content.size(); i++)
        {
            if (i != line_number)
            {
                write_myfile << file_content[i];
            }
            else
            {
                write_myfile << mew << endl;
            }
        }
        write_myfile.close();
    }

    return 0;
    }
}

int main (int argc, char *argv[]) {
   int cl_input;
  opterr = 0;
  // Checking the file flag is specified
  while ((cl_input = getopt(argc, argv, ":fms")) != -1)
    switch (cl_input)
      {
      case 'f':
        clean_line();
        break;
      case 'sonic':
        sonic_start();
        break;
      case 'mew':
        {
            mew_start();
            break;
        }
      case '?':
        if (optopt == 'f' || optopt == 'm' || optopt == 's')
          fprintf (stderr, "Options -%f and -%i require an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%f'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
}
}