/*

Author : Manas Rawat
Date : 06/11/2023
Problem : Seat Reservation Manager
Difficulty : Medium
Problem Link : https://leetcode.com/problems/seat-reservation-manager/
Video Solution : NA

*/


class SeatManager {
public:
    set<int> seats;
    SeatManager(int n) {
        for(int i = 1; i < n + 1; i++){
            seats.insert(i);    
        }
    }
    
    int reserve() {
        int take = *seats.begin();
        seats.erase(seats.begin());
        
        return take;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};