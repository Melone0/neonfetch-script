#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;    

int main() 
{
std::fstream file("/home/melone/Dokumente/.bashtest", std::ios::in);

if(file.is_open()) {
    std::string replace = "neofetch";
    std::string replace_with = "fart";
    std::string line;
    std::vector<std::string> lines;
    
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
        
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
}


ifstream myfile;
myfile.open("fhfhfhfh");
if (myfile.fail()){
    cout << "error open file";
    return 1;
}

else{

    vector<string> line;
string lines;

getline(myfile, line);

}




fstream read_file;
  
  // Open the file with the provided filename
  read_file.open(filename);
  
  // If file failed to open, exit with an error message and error exit status
  if (read_file.fail())
  {
    cout << "Error opening file." << endl;

    // returning 1 instead of 0 is a signal to the shell that something went 
    // wrong in the execution of the program
    return 1;
  }
  
  // Create a vector to store all the file lines, and a string line to store 
  // each line that we read
  vector<string> lines;
  string line;
  
  // Read each line of the file and store it as the next element of the vector,
  // the loop will stop when there are no more lines to read
  while (getline(read_file, line))
    lines.push_back(line);
  
  // Close our access to the file since we are done reading with it
  read_file.close();
  
  // The vector will now contain an element for each line in the file, so the 
  // size of the vector is the number of lines in the file.  Check to make 
  // sure the line number requested does not exceed the number of lines in 
  // the file, if it does, exit with an error message and status.
  if (line_number > lines.size())
  {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    // Inform user how many lines ARE in the file as part of the error message
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }
  
  // Create ofstream object for writing to the file
  ofstream write_file;
  
  // Open the file with the provided filename
  write_file.open(filename);
  
  // If the file failed to open, exit with an error message and exit status
  if (write_file.fail())
  {
    cout << "Error opening file." << endl;
    return 1;
  }
  
  // Write all of the lines stored in the vector back to the file, EXCEPT the
  // line that we want to replace, in that case we'll write the replacement 
  // text instead.

  // Line number 1 will be stored at vector index 0, line number 2 will be 
  // stored at vector index 1, and so on because vectors are zero-indexed, so 
  // decrement line_number to help us identify when we've reached the 
  // associated line in the file.
  line_number--;

  // Loop through the vector elements to write each line back to the file 
  // EXCEPT the line we want to replace
  for (int i = 0; i < lines.size(); i++)
  {
    // If the current index is not the line number we wish to replace, write 
    // the line back to the file, OTHERWISE if it IS the line we want to  
    // replace write the replacement text back to the file instead.
    if (i != line_number)
      write_file << lines[i] << endl;
    else 
      write_file << text << endl; 
  }
  
  // Close our access to the file since we are done working with it
  write_file.close();

  return 0;
}