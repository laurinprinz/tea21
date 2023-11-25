#ifndef WORKSPACES_TEA21_EXERCISE_004_BMP_H
#define WORKSPACES_TEA21_EXERCISE_004_BMP_H

#include <string>
#include <iostream>


class BMP {
    
    public:
        bool read(const std::string&  filename);
        bool write(const std::string&  filename);

    private:
        struct bmpFileHeader
        {
            char bfType[2] = {'X', 'X'};
            uint32_t bfSize = 0;
            uint32_t bfReserved = 0;
            uint32_t bfOffBits = 0;
            void print();
        };

        struct bmpInfoHeader
        {
            uint32_t biSize = 0;
            uint32_t biWidth = 0;
            uint32_t biHeight = 0;
            uint16_t biPlanes = 0;
            uint16_t biBitCount = 0;
            uint32_t biCompression = 0;
            uint32_t biSizeImage = 0;
            uint32_t biXPelsPerMeter = 0;
            uint32_t biYPelsPerMeter = 0;
            uint32_t biClrUsed = 0;
            uint32_t biClrImportant = 0;
            void print();
        };

        struct rgba
        {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            uint8_t alpha = 0;
            void print();
        };

        bmpFileHeader fileHeader;
        bmpInfoHeader infoHeader;
        rgba pixels;


};


#endif