#define Program.h

class  Program {
public:
    string name;
    string area;

    Program();
    Program(string name, string area);
}

Program::Program()
{
    name = "";
    area = "";
}

Program::Program(string name, string area)
{
    this->name = name;
    this->area = area;
}