#ifndef DATA_H
#define DATA_H
class Data {
    public:
        Data();
        ~Data();
        void setBits(int info, int row, int column);
        int getBits(int row, int column);
        void setData(void);
        void cleanData(void);
        void printData(void);
        
        void fill_parity(void);
        int parity_bits[5];
    private:
        bool pow_2(int num);
        int bits[4][4];
        static const int size = 16;

};
#endif