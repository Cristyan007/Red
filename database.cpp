#include "database.h"

database::database()
{

}

void database::assign_name(string name)
{
    this->name = name;
}

void database::assign_path(string path)
{
    this->path = path;
}
void database::read_all_database()
{
    fstream db;
    db.open(path+name, ios_base::in);
    if(db.is_open()){
        while(!db.eof()){
            info_db.push_back(db.get());
        }
        info_db.pop_back();
        db.close();
    }

}


string database::get_row_database(unsigned int row)
{
    read_all_rows();
    return v_row[row];
}

vector<string> database::get_col_database(unsigned int col, char segmentar)
{
    vector<string> aux, final;
    read_all_rows();
    for (unsigned long long i = 0; i < v_row.size(); ++i) {
        aux = split_string(segmentar,v_row[i]);
        final.push_back(aux[col]);
    }
    return final;
}


void database::append_data(string data, string a)
{
    fstream db;
    db.open(path+name, ios_base::app);
    if(db.is_open()) {
        a = a + data;
        db << a;
    }
}

void database::delete_row(unsigned int row)
{
    read_all_database();
    v_row.erase(v_row.begin()+row);
    save_data(vector2string('\n',v_row));
}

void database::inser_row(string data, unsigned int i)
{
    vector<string> info;
    read_all_database();
    info = split_string('\n',info_db);
    if (i<info.size()) {
        info.insert(info.begin()+i,data);
        save_data(vector2string('\n',info));
    }
}

bool database::vacioOrfull()
{
    fstream db;
    db.open(path+name, ios_base::in);
    if(db.is_open()){
        cout<<'\t'<<"--- NODOS CARGADOS ---"<<'\t'<<endl;
        return true;
    }
    cout<<"Algo paso con el archivo. Puede que sea la ruta o el nombre. "<<endl<<endl;
    return false;
}


//PRIVADAAAAAAAAD
void database::read_all_rows()
{
    read_all_database();
    v_row = split_string('\n', info_db);
}

vector<string> database::split_string(char a, string info)
{
    unsigned int pos = 0;
    int p_find;
    vector<string> rows;

    p_find = info.find(a,pos);
    while (p_find != -1) {
        rows.push_back(info.substr(pos,p_find-pos));
        pos = p_find+1;
        p_find = info.find(a,pos);
    }
    rows.push_back(info.substr(pos,info.size()-pos)) ;
    return rows;
}


string database::get_all_database()
{
    read_all_database();
    return info_db;
}

string database::vector2string(char a, vector<string> info)
{
    string aux = "";
    for (unsigned long long i = 0; i < info.size(); ++i) {
        aux = aux.append(info[i]);
        aux.push_back(a);
    }
    aux.pop_back();
    return aux;
}

void database::save_data(string data)
{
    fstream db;
    db.open(path+name, ios_base::out);
    db<<data;
    db.close();
}



