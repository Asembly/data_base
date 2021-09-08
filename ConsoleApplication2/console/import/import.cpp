#include"import.h"
#include"comands.h"

void database::Importer::printAll() {
    checkFile();

    while (!input_.eof()) {
        getline(input_, names_);
        cout << indexer_<< " - " << names_ << endl;
        indexer_++;
    }

    input_.close();
}
void database::Importer::checkPassword() {
    cout << "Write password:";
    cin >> password_;

    if (password_ == "+") {
        cout << "Password is correct\n";
    }
    else {
        cout << "Password is not correct\n";
        checkPassword();
    }
    system("cls");
}
void database::Importer::checkFile() {
    input_.open(path_);
    if (!input_.is_open()) {
        printf("File is: not open\n");
        exit(0x001);
    }
    else {
        printf("File is: open\n");
    }
    system("cls");
}
void database::Importer::loop() {
    checkPassword();
    cout << "Data Base (9 Á)" << endl;
    while (true) {
        cin >> command_;
        switch (command_) {
        case ALL:
            printAll();
            break;
        case EXIT:
            system("cls");
            exit(0);
            break;
        case SWITCH_FILE:
            cout << "Enter new path"<<endl;
            cin >> path_;
            break;
        default:
            cout << "Comands:\nALL_PRINT(0)\nEXIT(1)"<<endl;
        }
    }
}

database::Importer::Importer(string path) {
	this->path_ = path;
}
database::Importer::~Importer(){
	input_.close();
}