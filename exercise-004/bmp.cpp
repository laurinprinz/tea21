#include "bmp.h"
#include <fstream>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>


template<typename T>
static void read_value(std::fstream& file, T* value)
{
    file.read(reinterpret_cast<char*>(value), sizeof(T));
}

void BMP::bmpFileHeader::print()
{
    fmt::println("======The Bitmapfile Fileheader======");
    fmt::println("The start: {}, {}", bfType[0], bfType[1]);
    fmt::println("The Size in Bytes: {}", bfSize);
    fmt::println("The offset in Bytes: {}", bfReserved);
    fmt::println("The offset in Bytes: {}", bfOffBits);
}

void BMP::bmpInfoHeader::print()
{
    fmt::println("======The Bitmapfile Infoheader======");
    fmt::println("Size: {}", biSize );
    fmt::println("Width: {}", biWidth);
    fmt::println("Height: {}", biHeight);
    fmt::println("Planes: {}", biPlanes);
    fmt::println("Bit Count: {}", biBitCount);
    fmt::println("Compression: {}", biCompression);
    fmt::println("Size Image: {}", biSizeImage);
    fmt::println("X Pels: {}", biXPelsPerMeter);
    fmt::println("Y Pels: {}", biYPelsPerMeter);
    fmt::println("CLR Used: {}", biClrUsed);
    fmt::println("CLR Important: {}", biClrImportant);
}

void BMP::rgba::print()
{
    fmt::println("======The Bitmapfile Colors======");
    fmt::println("Red: {}", red);
    fmt::println("Green: {}", green);
    fmt::println("Blue: {}", blue);
    fmt::println("Alpha: {}", alpha);

}



bool BMP::read(const std::string& filename)
{

    auto ret = false;
    std::fstream input_file(filename, std::ios::binary | std::ios::in);

    if(!input_file.is_open())
    {
        fmt::println("Unable to open the file: {}", filename);
        return ret;
    }

    read_value(input_file, &fileHeader.bfType);
    read_value(input_file, &fileHeader.bfSize);
    read_value(input_file, &fileHeader.bfReserved);
    read_value(input_file, &fileHeader.bfOffBits);
    fileHeader.print();

    read_value(input_file, &infoHeader.biSize);
    read_value(input_file, &infoHeader.biWidth);
    read_value(input_file, &infoHeader.biHeight);
    read_value(input_file, &infoHeader.biPlanes);
    read_value(input_file, &infoHeader.biBitCount);
    read_value(input_file, &infoHeader.biCompression);
    read_value(input_file, &infoHeader.biSizeImage);
    read_value(input_file, &infoHeader.biXPelsPerMeter);
    read_value(input_file, &infoHeader.biYPelsPerMeter);
    read_value(input_file, &infoHeader.biClrUsed);
    read_value(input_file, &infoHeader.biClrImportant);
    infoHeader.print();

    int vec_size = infoHeader.biHeight * infoHeader.biWidth;
    int padding = (infoHeader.biWidth * 3) % 4;
    int fill;

    

    if(padding != 0)
    {
        fill = 4 - padding;
    } 

    //fmt::println("{}, {}", padding, fill);
    int buffer [infoHeader.biHeight][infoHeader.biWidth];
    int filledBuffer [infoHeader.biHeight][infoHeader.biWidth+fill];

    

    for(int i = 0; i < infoHeader.biHeight; i++)
    {
        int count = 0;
        //fmt::println("Alpha von Pixelreihe {}: ", i);
        for(int x = 0; x < infoHeader.biWidth; x++)
        {
               
            read_value(input_file, &pixels.red);
            read_value(input_file, &pixels.green);
            read_value(input_file, &pixels.blue);
            pixels.alpha = (pixels.red + pixels.green + pixels.blue) / 3;
            //pixels.print();

            buffer[i][x] = pixels.alpha;
            //fmt::print("{}, ", buffer[i][x]);
            
        }

        for (int u = 0; u < infoHeader.biWidth; ++u)
        {
            filledBuffer[i][u] = buffer[i][u];
        }
        
    }

    for (int c = 0; c < infoHeader.biWidth+fill; c++)
    {
        fmt::print("{}, ", filledBuffer[0][c]);
    }
    
    
    std::string asciiImage;
    std::vector<char> asciiChars = {'_', '.', ':', '-', '=', '+', '*', '#', '%', '@', ' '};

    for(int i = 0; i < infoHeader.biHeight; i++)
    {
        for(int x = 0; x < infoHeader.biWidth; x++)
        {
            asciiImage += asciiChars[buffer[i][x] /25.5];
        }
        asciiImage += '\n';
    }

    std::string filePath = "/workspaces/tea21/exercise-004/ascii_image.txt";

    std::ofstream outputFile(filePath);
    if(outputFile.is_open())
    {
        outputFile << asciiImage;
        outputFile.close();
    }
}

bool BMP::write(const std::string& filename)
{
    auto ret = false;
    return ret;
}