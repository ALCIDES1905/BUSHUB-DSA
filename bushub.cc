#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        map<string , pair<int , string>> mp;
        node * next;
        node(string s , int fare , string bus_id){
            string name = s;
            int f = fare;
            string b = bus_id;
            mp[name] = make_pair(f , bus_id);
            next = NULL;
        }
};

class graph{
    public:
        unordered_map<string , list<string>> graph_map;

        void addedge(string u , string v){
            graph_map[u].push_back(v);
        }
};

class bus {
public:
    string bus_id;
    vector<pair<int, bool>> available_seats;
    string route_id;

    //Default constructor
    bus() : bus_id(""), route_id("") {
        for (int i = 1; i <= 40; i++) {
            available_seats.push_back(make_pair(i, true));
        }
        available_seats.push_back(make_pair(40, true));
    }
    

    // Parameterized constructor
    bus(string id, string r) : bus_id(id), route_id(r) {
        for (int i = 1; i <= 40; i++) {
            available_seats.push_back(make_pair(i, true));
        }
        available_seats.push_back(make_pair(40, true));
    }
};

class route {
public:
    string route_id;
    int distance;
    string departure_time;
    string arrival_time;
    string starting_station;

    // Default constructor
    route() : route_id(""), distance(0), departure_time(""), arrival_time(""), starting_station("") {}

    // Parameterized constructor
    route(string rid, int d, string dt, string at, string ss) : route_id(rid), distance(d), departure_time(dt), arrival_time(at), starting_station(ss) {}
};


class bus_map{
    public:
        map<string , pair<int , string>>  mp;
};



void add_bus(map<string , pair<int , string>>  &mp){
    cout << "start" << endl;
    bool insert = true;
    string bus_id; int capacity ; string first_station; int current_passengers;
    while(insert){
        cin >> bus_id;
        cin >> capacity;
        cin >> first_station;
        cin >> current_passengers;
        cin >> insert;
        mp[bus_id] = make_pair(capacity , first_station);
    }
}

void display_buses(map<string, pair<int, string>> mp , node * arr[] , int size) {
    cout << "\n\n\t\t\t***** BUS DETAILS *****\n\n";

    if (mp.empty()) {
        cout << "\t\t\tNo buses available.\n";
        return;
    }


    for (auto bus_entry : mp) {
        string bus_id = bus_entry.first;
        int capacity = bus_entry.second.first;
        string first_station = bus_entry.second.second;

        // Display a small ASCII art bus for each entry
        cout << "         ______________________________________________________\n";
        cout << "        ||     ||     ||     ||     ||     ||     ||     ||     ||\n";
        cout << "      __||_____||_____||_____||_____||_____||_____||_____||_____||_____\n";
        cout << "     |                                                               O |\n";
        cout << "     |  BUSHUB   " << first_station << "   BUSHUB   BUSHUB   BUSHUB    |\n";
        cout << "     |________________________________________________________|________|\n";
        cout << "    |_______________________________________________________________|\n";
        cout << "       (O) o                                                    (O)\n";
        

        cout << "\n\tBus ID         : " << bus_id;
        cout << "\n\tCapacity       : " << capacity;
        cout << "\n\tComplete Route : ";
        for(int i = 0 ; i < size; i++){
            if(arr[i]->mp.begin()->first == first_station){
                node * temp = arr[i];
                node * move = temp;
                while(move != NULL){
                    if(move->next == NULL){
                        cout << move->mp.begin()->first;
                        move = move->next;
                    }
                    else{
                        cout << move->mp.begin()->first << " -> ";
                        move = move->next;
                    } 
                }
                break;
            }
        }
        cout << "\n\t-----------------------------------------------\n";
    }

    cout << "\n\n";
}


class passenger{
    public:
        string username;
        int ticket_no;
        passenger(){
            username = " ";
        }
};

class ticket{
    public:
    string username;
    int ticket_no;
    string bus_id;
    vector<int> seats;
    string starting_station;
    string destination_station;
    int fare;
};


void printBill(string starting_station, string destination_station, string bus_id, int fare , int total_fare, int total_members, vector<int>& bookings,  map<string, pair<bus, route>>& completeMap , int &ticket_no) {
    bus bus_obj = completeMap[bus_id].first;  
    route route_obj = completeMap[bus_id].second; 

    cout << "=============================================================\n";
    cout << "|                     **  BUSHUB  **                        |\n";
    cout << "|                *** Ticket Booking Details ***             |\n";
    cout << "=============================================================\n";

    cout << "| Ticket No.     : " << ticket_no << endl;
    cout << "| Bus ID         : " << bus_id << endl;
    cout << "| Route          : " << starting_station << " --> " << destination_station << endl;
    cout << "| departure Time : " << route_obj.departure_time << endl;
    cout << "| arrival Time   : " << route_obj.arrival_time << endl;
    cout << "|============================================================\n";

    cout << "| Seats Booked: ";
    for (size_t i = 0; i < bookings.size(); i++) {
        if (i == bookings.size() - 1)
            cout << bookings[i]; 
        else
            cout << bookings[i] << ", ";
    }
    cout << endl;

    cout << "| Total Members: " << total_members << " people" << endl;

    cout << "| Fare per Person: Rs " << fare << endl;
    cout << "| Fare per female person: Rs " << 0 << endl;
    cout << "| Fare per child: Rs " << fare/2 << endl;
    cout << "| Total Fare     : Rs " << total_fare << endl;

    cout << "=============================================================\n";
    cout << "| Thank you for choosing BusHub!                            |\n";
    cout << "| We wish you a pleasant journey.                           |\n";
    cout << "=============================================================\n";

    for(int i= 0 ; i < 4 ; i++){
        cout << endl;
    }
}

void display_ticket(string starting_station, string destination_station, string bus_id, int total_fare, int total_members,  vector<int>& bookings,  map<string, pair<bus, route>>& completeMap , int ticket_no){
    bus bus_obj = completeMap[bus_id].first;  
    route route_obj = completeMap[bus_id].second;
    cout << "=============================================================\n";
    cout << "|                     **  BUSHUB  **                        |\n";
    cout << "|                *** Ticket Booking Details ***             |\n";
    cout << "=============================================================\n";

    cout << "| Ticket No.     : " << ticket_no << endl;
    cout << "| Bus ID         : " << bus_id << endl;
    cout << "| Route          : " << starting_station << " --> " << destination_station << endl;
    cout << "| departure Time : " << route_obj.departure_time << endl;
    cout << "| arrival Time   : " << route_obj.arrival_time << endl;
    cout << "|============================================================\n";

    cout << "| Seats Booked: ";
    for (size_t i = 0; i < bookings.size(); i++) {
        if (i == bookings.size() - 1)
            cout << bookings[i]; 
        else
            cout << bookings[i] << ", ";
    }
    cout << endl;

    cout << "| Total Members: " << total_members << " people" << endl;
    cout << "| Total Fare     : Rs " << total_fare << endl;

    cout << "=============================================================\n";
    cout << "| Thank you for choosing BusHub!                            |\n";
    cout << "| We wish you a pleasant journey.                           |\n";
    cout << "=============================================================\n";
    cout << endl;
    for(int i= 0 ; i < 4 ; i++){
        cout << endl;
    }

}

void display_seats(map<string, pair<bus, route>>& completeMap, string bus_id) {
    bus& bus_obj = completeMap[bus_id].first;
    route route_obj = completeMap[bus_id].second;

    cout << "Seats available in bus " << bus_id << endl;
    cout << "Displaying seats for Bus ID: " << bus_id << " on Route: " << route_obj.route_id << "\n";
    cout << "----------------------------------\n";

    int count = 0;
    for(int i = 1 ; i <= 40 ; i++){
        if(bus_obj.available_seats[i].second == true){
            cout << i << "[O]" << "       ";
            count ++;
        }
        else{
            cout << i << "[X]" << "       ";
            count++;
        }
        if(count == 4){
            cout << endl;
            count = 0;
        }
        
    }

    cout << "----------------------------------\n";
    cout << "[O] - Available  [X] - Booked\n";
    for(int i = 0 ; i < 5 ; i++){
        cout << endl;
    }
}


void printing_ticket(string starting_station, string destination_station, string bus_id, int fare, map<string, pair<bus, route>>& completeMap, vector<pair<passenger , string>> &passengers_vector , vector<pair<ticket , int>> &tickets_vector  , int& randomno) {
    int adults = 0, children = 0, male = 0, female = 0, total_fare = 0, total_seats_needed = 0;

    bus& bus_obj = completeMap[bus_id].first;
    route& route_obj = completeMap[bus_id].second;

    cout << "\n==============================================\n";
    cout << "           ** Ticket Booking **\n";
    cout << "==============================================\n";
    cout << "\nHow many adults? ";
    cin >> adults;

    cout << "\nHow many of them are adult male? ";
    cin >> male;
    female = adults - male;

    cout << "\nHow many children below the age of 10? ";
    cin >> children;

    total_seats_needed = male + female + children;
    total_fare = (male * fare) + (children * (fare / 2)); 

    display_seats(completeMap, bus_id);
    int count = 0;
    for(int i = 0 ; i <= 40 ; i++){
        if(bus_obj.available_seats[i].second == true){
            count++;
        }
    }
    if(count < total_seats_needed){
        cout << "\n==============================================\n";
        cout << "          Sorry , the bus is full! \n";
        cout << "==============================================\n";
        return;
    }

    vector<int> bookings;
    cout << "\nPlease enter the seat numbers you want to book (1-40): \n";

    for (int i = 0; i < total_seats_needed; i++) {
        label5:
        int seat_no;
        cout << "\nEnter seat number: ";
        cin >> seat_no;

        if (bus_obj.available_seats[seat_no].second == false) { 
            cout << "\nSeat " << seat_no << " is already booked! Please choose another seat.\n";
            goto label5;
        }   

        if ((seat_no <= 40 || seat_no >= 1) ) {
            bus_obj.available_seats[seat_no].second = false;
            bookings.push_back(seat_no);
            cout << "\nSeat " << seat_no << " booked successfully!\n";
        }
        else{
            cout << "\nInvalid seat number! Please enter a valid seat number between 1 and 40.\n";
            goto label5;
        } 
    }

    display_seats(completeMap, bus_id);
    cout << endl;
    ticket t1;
    t1.bus_id = bus_id;
    t1.destination_station = destination_station;
    t1.fare = total_fare;
    t1.ticket_no = randomno;
    t1.seats = bookings;
    t1.starting_station = starting_station;
    tickets_vector.push_back(make_pair(t1 , randomno));
    cout << "\n==============================================\n";
    label6:
    cout << "Printing your ticket...Please make the payment & enter your username below for confirmation: " << endl;
    string usnm;
    cin >> usnm;
    cout << "\n==============================================\n";
    int found = 0;
    for(int i = 0 ; i < passengers_vector.size() ; i++){
        if(usnm == passengers_vector[i].second){
            cout << "Thank you for you cooperation...." << endl;
            found++;
            t1.username = usnm;
            for(auto i : passengers_vector){
                if(i.second == usnm){
                    passenger &p_obj = i.first;
                    p_obj.ticket_no = randomno;
                }
            }
            break;
        }
    }
    if(found == 0){
        cout << "no username exist with this name....plz check it again" << endl;
        goto label6;
    }
    
    printBill(starting_station, destination_station, bus_id, fare, total_fare, total_seats_needed, bookings, completeMap , randomno);
    randomno++;
    cout << "\n==============================================\n";
    cout << "         ** Thank you for booking with us! **\n";
    cout << "==============================================\n";
    for(int i= 0 ; i < 4 ; i++){
        cout << endl;
    }
}

void book_Ticket(map<string , pair<int , string>>  &mp , node * arr[] , int size ,  map<string , pair<bus , route> > &completeMap , vector<pair<passenger , string>> &passengers_vector , vector<pair<ticket , int>> &tickets_vector , int& randomno){
    int bus_no, seat_no, fare, ticket_no;
    string starting_station , starting_station_id, destination_station, new_starting_Location;
    string actual_starting_station;


    cout << "\n=============================================================\n";
    cout << "   Please Enter desired Bus_id\n";
    cout << "=============================================================\n";
    cin >> starting_station_id;
    starting_station = completeMap[starting_station_id].second.starting_station;

    cout << "\n=============================================================\n";
    cout << "    Enter your boarding station\n";
    cout << "=============================================================\n";
    cin >> actual_starting_station;


    cout << "\n=============================================================\n";
    cout << "    Enter your destination station\n";
    cout << "=============================================================\n";
    cin >> destination_station;

    cout << "\n=============================================================\n";
    cout << "                  Please Wait...\n";
    cout << "=============================================================\n";

    int foundone = 0;
    int stations = 0;

    for (auto j : mp) {
        if (j.second.second == starting_station) {
            foundone++;

            if (starting_station != actual_starting_station) {
                new_starting_Location = actual_starting_station;
                stations = -1;

                for (int i = 0; i < size; i++) {
                    if (arr[i]->mp.begin()->first == starting_station) {
                        node *temp = arr[i];
                        node *move = temp;
                        int found = 0;

                        while (move != NULL) {
                            if (move->mp.begin()->first == destination_station) {
                                fare = 50* stations;
                                if((destination_station != new_starting_Location) && (fare <= 0)){
                                    cout << "\n===================================================================\n";
                                    cout << "    Sorry, the selected bus does not run from " << new_starting_Location << " to " << destination_station << ".\n";
                                    cout << "    Hopefully, we will reach your demands soon.\n";
                                    cout << "=============================================================\n";
                                    return;
                                }
                                else{
                                    cout << "\n===================================================================\n";
                                    cout << "    Bus ID " << j.first << " is available.\n";
                                    cout << "    Total fare: " << 50 * stations << " per person\n";
                                    cout << "\n    Do you want to book this ticket?\n";
                                    cout << "    1. Yes\n";
                                    cout << "    2. No\n";
                                    cout << "\n    Enter your choice: ";
                                    int b;
                                    cin >> b;
                                    while (true) {
                                            cin >> b;
                                            // Check if the input is invalid
                                            if (cin.fail()) {
                                                cin.clear(); // Clear the error flag
                                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                                                cout << "Invalid input. Please enter an integer: ";
                                            } 
                                            else {
                                                break; // Input is valid, break out of the loop
                                            }
                                    }
                                    found++;
                                    if (b == 1) {
                                        printing_ticket(actual_starting_station , destination_station , j.first , 50*stations , completeMap , passengers_vector , tickets_vector , randomno);
                                    } 
                                    else if (b == 2) {
                                        cout << "\n=============================================================\n";
                                        cout << "    We think you changed your mind.\n";
                                        cout << "    Hope to see you soon!\n";
                                        cout << "===============================================================\n";
                                        return;
                                    }
                                }
                                
                            }
                            stations++;
                            move = move->next;
                        }

                        if (found == 0) {
                                cout << "\n=============================================================\n";
                                cout << "    Sorry, the selected bus does not run from  " << new_starting_Location << " to " << destination_station << ".\n";
                                cout << "    Hopefully, we will reach your demands soon.\n";
                                cout << "===============================================================\n";
                        }

                        break;
                    }
                }
            } 
            else {
                for (int i = 0; i < size; i++) {
                    if (arr[i]->mp.begin()->first == starting_station) {
                        node *temp = arr[i];
                        node *move = temp;
                        int found = 0;

                        while (move != NULL) {
                            if (move->mp.begin()->first == destination_station) {
                                fare = 50* stations;
                                if((destination_station != starting_station) && (fare <= 0)){
                                    cout << "\n===================================================================\n";
                                    cout << "    Sorry, the selected bus does not run from  " << starting_station << " to " << destination_station << ".\n";
                                    cout << "    Hopefully, we will reach your demands soon.\n";
                                    cout << "=============================================================\n";
                                    return;
                                }
                                else{
                                    cout << "\n===================================================================\n";
                                    cout << "    Bus ID " << j.first << " is available.\n";
                                    cout << "    Total fare: " << 50 * stations << " per person\n";
                                    cout << "\n    Do you want to book this ticket?\n";
                                    cout << "    1. Yes\n";
                                    cout << "    2. No\n";
                                    cout << "\n    Enter your choice: ";
                                    int b;
                                    while (true) {
                                        cin >> b;

                                        // Check if the input is invalid
                                        if (cin.fail()) {
                                            cin.clear(); // Clear the error flag
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                                            cout << "Invalid input. Please enter an integer: ";
                                        } 
                                        else {
                                            break; // Input is valid, break out of the loop
                                        }
                                    }
                                    found++;
                                    if (b == 1) {
                                        printing_ticket(starting_station , destination_station , j.first , 50*stations , completeMap , passengers_vector , tickets_vector , randomno);
                                    } 
                                    else if (b == 2) {
                                        cout << "\n=============================================================\n";
                                        cout << "    We think you changed your mind.\n";
                                        cout << "    Hope to see you soon!\n";
                                        cout << "===============================================================\n";
                                        return;
                                    }
                                }
                                
                            }
                            stations++;
                            move = move->next;
                        }

                        if (found == 0) {
                                cout << "\n=============================================================\n";
                                cout << "    Sorry, the selected bus does not run from  " << starting_station << " to " << destination_station << ".\n";
                                cout << "    Hopefully, we will reach your demands soon.\n";
                                cout << "===============================================================\n";
                        }

                        break;
                    }
                }
            }
        }
    }

    if (foundone == 0) {
        cout << "\n=============================================================\n";
        cout << "    Sorry, the selected bus does not run from  " << starting_station << " to " << destination_station << ".\n";
        cout << "    Hopefully, we will reach your demands soon.\n";
        cout << "=============================================================\n";
    }
    return;

}

void cancel_Ticket(map<string, pair<int, string>> &mp, node *arr[], int size,
                   map<string, pair<bus, route>> &completeMap,
                   vector<pair<ticket, int>> &tickets_vector,
                   vector<pair<passenger, string>> &passengers_vector) {

    cout << "\n=============================================================\n";
    cout << "|            It's sad to see you cancel your ticket...        |\n";
    cout << "|         Missing the chance to travel with BUSHUB!           |\n";
    cout << "===============================================================\n\n";

    cout << "Are you sure you want to cancel your ticket?\n";
    cout << "=============================================================\n";
    cout << "|                    1) Yes                                 |\n";
    cout << "|                    2) No                                  |\n";
    cout << "=============================================================\n";
    cout << "Enter your choice: ";
    int b;
    while (true) {
            cin >> b;

            // Check if the input is invalid
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer: ";
            } 
            else {
                break; // Input is valid, break out of the loop
            }
        }

    if (b == 1) {
        cout << "\n============================================================\n";
        cout << "|              Please enter your unique ticket number:       |\n";
        cout << "=============================================================\n";
        int a;
        cin >> a;

        int found = 0;
        for (int i = 0; i < tickets_vector.size(); i++) {
            if (tickets_vector[i].second == a) {
                found++;
                tickets_vector[i].second = -1;
                tickets_vector[i].first.ticket_no = -1;

                string usnm = tickets_vector[i].first.username;
                string bus_id = tickets_vector[i].first.bus_id;

                for (auto &j : passengers_vector) {
                    if (j.second == usnm) {
                        j.first.ticket_no = -1;
                    }
                }

                bus &obj = completeMap[bus_id].first;
                for (int k = 0; k < tickets_vector[i].first.seats.size(); k++) {
                    obj.available_seats[tickets_vector[i].first.seats[k]].second = true;
                }

                cout << "\n=====================================================================================\n";
                cout << "|Your ticket has been cancelled successfully! Refund will be processed within 24 hrs. |\n";
                cout << "=======================================================================================\n";
                return;
            }
        }

        if (found == 0) {
            cout << "\n=============================================================\n";
            cout << "|             Sorry, ticket number " << a << " not found.      |\n";
            cout << "|           Please re-enter your ticket number carefully.      |\n";
            cout << "=============================================================\n";
            cout << endl;
            return;
        }
    } else if (b == 2) {
        cout << "\n=============================================================\n";
        cout << "|                 Thank you for trusting in BUSHUB!                |\n";
        cout << "|                Returning to the User Menu...                  |\n";
        cout << "=============================================================\n";
        return;
    }
}

class route_map{
    public:
    node * arr[10];
    int size;
};


void add_routes(node * arr[] , int size){
    cout << "start" << endl;
   bool button = true;
   string bus_id ; int fare; string station_name;
   while(button){
        for(int i = 0 ; i < size ; i++){
            cin >> station_name;
            cin >> fare;
            cin >> bus_id;
            
            node* temp = new node(station_name , fare , bus_id);
            arr[i] = temp;
            node * move = temp;
            int button = 1;
            while(button){
                cin >> station_name;
                cin>> fare;
                cin >> bus_id;
                
                node* temp1 = new node(station_name , fare , bus_id);
                move->next = temp1;
                move = move->next;
                cin >> button;
            }
        }
        button = false;
    }
}

void display_routes(node * arr[], int &size) {
    cout << "\n\n\t\t\t***** ROUTES DISPLAY *****\n\n";

    
    for (int i = 0; i < size; i++) {
        node* temp = arr[i];
        node* move = temp;

       
        if (move == nullptr) {
            cout << "\t\t\tNo route available at index " << i + 1 << endl;
            cout << "\t\t\t--------------------------------------\n";
           return;
        }

        
        cout << "\n\t\t\tRoute " << i + 1 << ":\n";
        cout << "\t\t\t=================================================\n\t\t\t";

        
        while (move != NULL) {
            
            string station_name = move->mp.begin()->first;
            int fare = move->mp.begin()->second.first;
            string bus_id = move->mp.begin()->second.second;

           
            int box_width = station_name.length() + 4; 
            string top_bottom_border = "+" + string(box_width - 2, '-') + "+";
            string side_border = "|" + string((box_width - 2 - station_name.length()) / 2, ' ') + station_name +
                                 string((box_width - 2 - station_name.length()) / 2 + (box_width - 2 - station_name.length()) % 2, ' ') + "|";

            
            cout << top_bottom_border << "   ";
            move = move->next;
        }
        
        
        move = arr[i];
        cout << "\n\t\t\t";
        
        
        while (move != NULL) {
            string station_name = move->mp.begin()->first;
            int box_width = station_name.length() + 4;
            string side_border = "|" + string((box_width - 2 - station_name.length()) / 2, ' ') + station_name +
                                 string((box_width - 2 - station_name.length()) / 2 + (box_width - 2 - station_name.length()) % 2, ' ') + "|";

            cout << side_border << "   ";
            if (move->next != NULL) {
                cout << "  -->  ";
            }
            move = move->next;
        }

        cout << "\n\t\t\t";
        move = arr[i];
        while (move != NULL) {
            string station_name = move->mp.begin()->first;
            int box_width = station_name.length() + 4;
            string top_bottom_border = "+" + string(box_width - 2, '-') + "+";

            cout << top_bottom_border << "   ";
            if (move->next != NULL) {
                cout << "    ";
            }
            move = move->next;
        }
        
        
        cout << "\n\n\t\t\tFare & Bus ID Details:\n\t\t\t";
        move = arr[i];
        while (move != NULL) {
            int fare = move->mp.begin()->second.first;
            string bus_id = move->mp.begin()->second.second;
            cout << "[Fare: " << fare << ", Bus ID: " << bus_id << "]";
            if (move->next != NULL) {
                cout << "  -->  ";
            }
            move = move->next;
        }

        cout << "\n\t\t\t=================================================\n";
    }

    cout << "\n\n";
}



class user{
    string username;
    string password;
    int ticket_no;
};

class database{
    public:
    map < string , string> credentials;
};

vector<string> find_shortest_path(graph &graphs , string & start , string & destination) {
    unordered_map<string, string> parent;
    queue<string> q;
    unordered_map<string, bool> visited;

    q.push(start);
    visited[start] = true;
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == destination) {
            vector<string> path;
            for (string at = destination; !at.empty(); at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const string &neighbor : graphs.graph_map[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    return {}; // Return empty vector if no path is found
}

void display_shortest_path(graph &graphs) {
    cout << "\n=========================================\n";
    cout << "           DTC BUS ROUTE FINDER          \n";
    cout << "=========================================\n\n";

    cout << "Enter your source station: ";
    string start;
    cin >> start;
    cout << "Enter your destination station: ";
    string destination;
    cin >> destination;

    vector<string> path = find_shortest_path(graphs, start, destination);

    cout << "\n-----------------------------------------\n";
    if (!path.empty()) {
        cout << "Shortest path from " << start << " to " << destination << ":\n\n";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "[" << path[i] << "]";
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\n\nRoute successfully displayed!\n";
    } else {
        cout << "No path found from " << start << " to " << destination << ".\n";
    }
    cout << "-----------------------------------------\n";
}

void algorithm2(string username , node * arr[] , int size , map<string, pair<int, string>>& mp , map<string , pair<bus , route> > &completeMap , vector<pair<passenger , string>> &passengers_vector , vector<pair<ticket , int>> &tickets_vector , int& randomno , graph & graphs){
    //  declaring all clases
        
    //_______________________________________________________________


     // After login and registration
    int choice;
    label3:
        cout << "==========================================================\n";
        cout << "|       * * *    Welcome to the User Menu   * * *        |\n";
        cout << "|========================================================|\n";
        cout << "|                                                        |\n";
        cout << "|       1)   Display All Routes                          |\n";
        cout << "|       2)   Display Buses                               |\n";
        cout << "|       3)   Book Ticket                                 |\n";
        cout << "|       4)   Cancel Ticket                               |\n";
        cout << "|       5)   Display Ticket Details                      |\n";
        cout << "|       6)   Find Shortest Distance                      |\n";
        cout << "|       7)   Logout                                      |\n";
        cout << "|                                                        |\n";
        cout << "==========================================================|\n";
        cout << "\n    Enter your choice: ";
       

        while (true) {
        cin >> choice;

        // Check if the input is invalid
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter an integer: ";
        } else {
            break; // Input is valid, break out of the loop
        }
    }

        if(choice<1 || choice > 7){
            cout << "Invalid choice. Please choose a valid option.\n";
            goto label3;
        }

    while(choice != 7){
        if(choice == 1){
            display_routes(arr , size);
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
        else if(choice == 2){
            display_buses(mp , arr , size);
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
        else if(choice == 3){
            book_Ticket(mp , arr , size , completeMap , passengers_vector , tickets_vector , randomno);
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
        else if(choice == 4){
            cancel_Ticket(mp , arr , size , completeMap ,tickets_vector ,  passengers_vector);
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
        else if(choice == 5){
            cout << "Enter your ticket number: ";
            int a;
            cin >> a;
            int found = 0;
            for(auto i : tickets_vector){
                if(i.second == a){
                    found++;
                    ticket &obj = i.first;
                    int count = 0;
                    for(auto j : obj.seats){
                        count++;
                    }
                    display_ticket(obj.starting_station , obj.destination_station , obj.bus_id , obj.fare , count , obj.seats , completeMap , a);
                    break;
                }
            }       
            if(found == 0){
                cout << "------------------------------------------------------->\n";
                cout << "Ticket not found! \n";
                cout << "Try again" << endl;
                cout << "------------------------------------------------------->\n";
            }
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
        else if(choice == 6){
            display_shortest_path(graphs);
            cout << "Taking you back to the main menu... Please wait! \n";
            cout << "------------------------------------------------------->\n";
            goto label3;
        }
    }
}


void algorithm(node * arr[] , int size , map<string, pair<int, string>>& mp , map<string , pair<bus , route> > &completeMap , vector<pair<passenger , string>>& passengers_vector , vector<pair<ticket , int>> &tickets_vector , int& randomno , graph & graphs){
//  declaring all clases
    database cred;
//_______________________________________________________________

    for(int i = 0 ; i < 10 ; i++){
        cout << endl;
    }
    int firstChoice;
    cout << "=========================================================================\n";
    cout << "|                        Welcome to BUS HUB                             |\n";
    cout << "|              <Your most trustable place to book buses>                |\n";
    cout << "=========================================================================\n\n";

    // Wider Bus ASCII Art
    cout << "         ______________________________________________________\n";
    cout << "        ||     ||     ||     ||     ||     ||     ||     ||     ||\n";
    cout << "      __||_____||_____||_____||_____||_____||_____||_____||_____||__\n";
    cout << "     |                                                      ________|\n";
    cout << "     |  BUSHUB   BUSHUB   BUSHUB   BUSHUB   BUSHUB   BUSHUB|         |\n";
    cout << "     |_____________________________________________________|_________|\n";
    cout << "    |______________________________________________________________|\n";
    cout << "       (O) o                                                    (O)\n";


    while(true){
    int firstChoice;
    
    cout << "\n========================================================================\n";
    cout << "\t\t\t      * * *  MAIN MENU  * * *\n";
    cout << "\t\t\t--------------------------------\n";
    cout << "\t\t\t|      1. Register            |\n";
    cout << "\t\t\t|      2. Log In              |\n";
    cout << "\t\t\t|      3. Exit                |\n";
    cout << "\t\t\t--------------------------------\n";
    cout << "========================================================================\n";
    cout << "\t\t\tEnter your choice: ";
    while (true) {
            cin >> firstChoice;

            // Check if the input is invalid
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer: ";
            } 
            else {
                break; // Input is valid, break out of the loop
            }
        }

    if (firstChoice == 1) {
        label:
        cout << "\n====================================================\n";
        cout << "* * *  REGISTRATION PAGE  * * *\n";
        cout << "====================================================\n\n";

        cout << " * Enter your username: ";
        string usrnm;
        cin >> usrnm;

        // Check if username already exists
        for (auto i : cred.credentials) {
            if (i.first == usrnm) {
                cout << "\n* Username already exists! *\n";
                cout << "*  Please choose another username.\n\n";
                goto label;
            }
        }

        cout << " * Enter your password: ";
        string passwrd;
        cin >> passwrd;

        // Register the user
        cred.credentials[usrnm] = passwrd;
        passenger p1;
        passengers_vector.push_back(make_pair(p1 , usrnm));
        p1.username = usrnm;

        cout << "\n====================================================\n";
        cout << "* Congratulations! *\n";
        cout << "  You have successfully registered! Welcome, " << usrnm << "!\n";
        cout << "====================================================\n\n";
    }

    else if (firstChoice == 2) {
        label2:
        cout << "\n====================================================\n";
        cout << "* * *  LOGIN PAGE  * * *\n";
        cout << "====================================================\n\n";

        cout << " * Enter your username: ";
        string usrnm;
        cin >> usrnm;

        // Check if username exists
        bool found = false;
        for (auto i : cred.credentials) {
            if (i.first == usrnm) {
                found = true;
                cout << " * Enter your password: ";
                string passwrd;
                cin >> passwrd;

                if (passwrd == i.second) {
                    cout << "\n====================================================\n";
                    cout << "*  Welcome, " << usrnm << "!\n";
                    cout << "  You have successfully logged in!\n";
                    cout << "====================================================\n\n";
                    algorithm2(usrnm , arr , size , mp , completeMap , passengers_vector , tickets_vector , randomno , graphs);
                } else {
                    cout << "\n* Incorrect password! *\n";
                    cout << "*  Please try again.\n\n";
                    goto label2;
                }
            }
        }

        if (!found) {
            cout << "\n* Username does not exist! *\n";
            cout << "  Choose an option:\n";
            cout << "  1. Register\n";
            cout << "  2. Try login again\n\n";
            int choice;
            cout << " * Enter your choice: ";

        while (true) {
            cin >> choice;


            // Check if the input is invalid
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter an integer: ";
            } 
            else {
                break; // Input is valid, break out of the loop
            }
        }
            if (choice == 1) {
                goto label;
            } else if (choice == 2) {
                goto label2;
            }
        }
    }

        else if (firstChoice == 3) {
            cout << "\n====================================================\n";
            cout << "  Thank you for using our service!\n";
            cout << "====================================================\n";
            break;
            return;
        }

    }
}

void adding_edges(graph &graphs){
    graphs.addedge("Connaught_Place" , "Janpath");
    graphs.addedge("Connaught_Place" , "Mandi_House");
    graphs.addedge("Janpath" , "India_Gate");
    graphs.addedge("India_Gate" , "Khan_Market");
    graphs.addedge("India_Gate" , "Lodhi_Garden");
    graphs.addedge("Khan_Market" , "AIIMS");
    graphs.addedge("Khan_Market" , "Lodhi_Garden");
    graphs.addedge("Lodhi_Garden" , "Safdarjung_Tomb");
    graphs.addedge("Lodhi_Garden" , "AIIMS");
    graphs.addedge("Safdarjung_Tomb" , "AIIMS");
    graphs.addedge("AIIMS" , "South_Extension");
    graphs.addedge("AIIMS" , "Safdarjung_Tomb");
    graphs.addedge("South_Extension" , "INA_Market");
    graphs.addedge("INA_Market" , "Lajpat_Nagar");
    graphs.addedge("Lajpat_Nagar" , "Kalkaji_Mandir");
    graphs.addedge("Lajpat_Nagar" , "Nehru_Place");
    graphs.addedge("Nehru_Place" , "Govindpuri");
    graphs.addedge("Govindpuri" , "Okhla");
    graphs.addedge("Sarita_Vihar" , "Jasola");
    graphs.addedge("Jasola" , "Badarpur_Border");
    graphs.addedge("Jasola" , "Tughlakabad");
    graphs.addedge("Badarpur_Border" , "Faridabad_Border");
    graphs.addedge("Tughlakabad" , "Faridabad_Border");
    graphs.addedge("Tughlakabad" , "Badarpur_Border");
    graphs.addedge("Faridabad_Border" , "Palwal");
    graphs.addedge("Mandi_House" , "ITO");
    graphs.addedge("Mandi_House" , "Laxmi_Nagar");
    graphs.addedge("ITO" , "Indraprastha");
    graphs.addedge("Indraprastha" , "Akshardham");
    graphs.addedge("Laxmi_Nagar" , "Nirman_Vihar");
    graphs.addedge("Nirman_Vihar" , "Preet_Vihar");
    graphs.addedge("Preet_Vihar" , "Anand_Vihar");
    graphs.addedge("Kalkaji_Mandir" , "Nehru_Place");
    graphs.addedge("Okhla" , "Jasola");
    graphs.addedge("Okhla" , "Sarita_Vihar");
}

int main(){

    map<string , pair<bus , route> > completeMap;

    route_map routes;
    routes.size = 12;
    add_routes(routes.arr , 12);

    bus_map buses;
    add_bus(buses.mp);

    route rone("DTCROUTE_201", 5.2, "07:30 am", "07:45 am", "Connaught Place");
    route rtwo("DTCROUTE_202", 4.8, "07:50 am", "08:05 am", "Janpath");
    route rthree("DTCROUTE_203", 6.1, "08:15 am", "08:30 am", "Khan_Market");
    route rfour("DTCROUTE_204", 4.3, "07:45 am", "08:00 am", "India_Gate");
    route rfive("DTCROUTE_205", 5.6, "08:00 am", "08:18 am", "South Extension");
    route rsix("DTCROUTE_206", 4.9, "07:20 am", "07:35 am", "Lajpat Nagar");
    route rseven("DTCROUTE_207", 3.8, "07:55 am", "08:10 am", "Govindpuri");
    route reight("DTCROUTE_208", 5.1, "07:40 am", "07:55 am", "Sarita_Vihar");
    route rnine("DTCROUTE_209", 4.7, "08:10 am", "08:25 am", "Tughlakabad");
    route rten("DTCROUTE_210", 6.3, "08:15 am", "08:35 am", "Connaught_Place");
    route releven("DTCROUTE_211", 5.4, "07:50 am", "08:05 am", "Mandi_House");
    route rtwelve("DTCROUTE_212", 5.9, "08:05 am", "08:20 am", "Kalkaji_Mandir");

   bus one("DTC201" , rone.route_id);
   bus two("DTC202" , rtwo.route_id);
   bus three("DTC203" , rthree.route_id);
   bus four("DTC204" , rfour.route_id);
   bus five("DTC205" , rfive.route_id);
   bus six("DTC206" , rsix.route_id);
   bus seven("DTC207" , rseven.route_id);
   bus eight("DTC208" , reight.route_id);
   bus nine("DTC209" , rnine.route_id);
   bus ten("DTC210" , rten.route_id);
   bus eleven("DTC211" , releven.route_id);
   bus twelve("DTC212" , rtwelve.route_id);

    completeMap["DTC201"] = make_pair(one , rone);
    completeMap["DTC202"] = make_pair(two , rtwo);
    completeMap["DTC203"] = make_pair(three , rthree);
    completeMap["DTC204"] = make_pair(four , rfour);
    completeMap["DTC205"] = make_pair(five , rfive);
    completeMap["DTC206"] = make_pair(six , rsix);
    completeMap["DTC207"] = make_pair(seven , rseven);
    completeMap["DTC208"] = make_pair(eight , reight);
    completeMap["DTC209"] = make_pair(nine , rnine);
    completeMap["DTC210"] = make_pair(ten , rten);
    completeMap["DTC211"] = make_pair(eleven , releven);
    completeMap["DTC212"] = make_pair(twelve , rtwelve);

    vector<pair<passenger , string>> passengers_vector;
    vector<pair<ticket , int>> tickets_vector;
    int randomno = 135547;

    graph graphs;
    adding_edges(graphs);


    algorithm(routes.arr , routes.size , buses.mp , completeMap , passengers_vector , tickets_vector ,randomno , graphs);

    return 0;
}
