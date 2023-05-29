class ParkingSystem {
public:

    int small, big, medium; // global variables
    ParkingSystem(int big, int medium, int small) {
        // constructor to initialize the global variables
        this -> big = big;
        this -> small = small;
        this -> medium = medium;
    }
    
    bool addCar(int carType) {
        // if the car type is 1 and the big is 0 then return false
        if (carType == 1 && !big) return false;
        // if the car type is 2 and the medium is 0 then return false
        if (carType == 2 && !medium) return false;
        // if the car type is 3 and the small is 0 then return false
        if (carType == 3 && !small) return false;
        
        // if the car type is 1 then decrement the big
        if (carType == 1) --big;
        // if the car type is 2 then decrement the medium
        if (carType == 2) --medium;
        // if the car type is 3 then decrement the small
        if (carType == 3) --small;
       
        // return true if the car is added
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */