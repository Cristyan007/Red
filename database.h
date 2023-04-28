#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include<fstream>
#include<vector>

using namespace std;

class database
{
public:
    database();
    void assign_name(string name);
    void assign_path(string path);
    string get_all_database();
    string get_row_database(unsigned int row);
    vector<string> get_col_database(unsigned int col, char segmentar);
    void append_data(string data, string a);
    void delete_row(unsigned int row);
    void inser_row(string data, unsigned i);

private:
    void save_data(string data);
    void read_all_rows();
    void read_all_database();
    vector<string> split_string(char a, string info);
    string vector2string(char a, vector<string> info );
     string name, path, info_db;
     vector<string> v_row,v_col;
};































#endif // DATABASE_H
