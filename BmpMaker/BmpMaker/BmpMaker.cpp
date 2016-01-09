/*
 ***************************************************************************
 *                                                                         *
 *                         Platform Independent                            *
 *                   Bitmap Image Reader Writer Library                    *
 *                                                                         *
 * Author: Arash Partow - 2002                                             *
 * URL: http://www.partow.net                                              *
 *                                                                         *
 * Copyright notice:                                                       *
 * Free use of the Platform Independent Bitmap Image Reader Writer Library *
 * is permitted under the guidelines and in accordance with the most       *
 * current version of the Common Public License.                           *
 * http://www.opensource.org/licenses/cpl1.0.php                           *
 *                                                                         *
 ***************************************************************************
*/

/*
   Note: In some of the tests a bitmap image by the name of 'image.bmp'
         is required. If not present the test will fail.
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "bitmap_image.h"


inline void test01()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test01() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   image.save_image("test01_saved.bmp");
}

inline void test02()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test02() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   image.save_image("test02_saved.bmp");

   image.vertical_flip();
   image.save_image("test02_saved_vert_flip.bmp");
   image.vertical_flip();

   image.horizontal_flip();
   image.save_image("test02_saved_horiz_flip.bmp");
}

inline void test03()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test03() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   bitmap_image subsampled_image1;
   bitmap_image subsampled_image2;
   bitmap_image subsampled_image3;

   image.subsample(subsampled_image1);
   subsampled_image1.save_image("test03_1xsubsampled_image.bmp");

   subsampled_image1.subsample(subsampled_image2);
   subsampled_image2.save_image("test03_2xsubsampled_image.bmp");

   subsampled_image2.subsample(subsampled_image3);
   subsampled_image3.save_image("test03_3xsubsampled_image.bmp");
}

inline void test04()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test04() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   bitmap_image upsampled_image1;
   bitmap_image upsampled_image2;
   bitmap_image upsampled_image3;

   image.upsample(upsampled_image1);
   upsampled_image1.save_image("test04_1xupsampled_image.bmp");

   upsampled_image1.upsample(upsampled_image2);
   upsampled_image2.save_image("test04_2xupsampled_image.bmp");

   upsampled_image2.upsample(upsampled_image3);
   upsampled_image3.save_image("test04_3xupsampled_image.bmp");
}

inline void test05()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test05() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   image.set_all_ith_bits_low(0);
   image.save_image("test05_lsb0_removed_saved.bmp");
   image.set_all_ith_bits_low(1);
   image.save_image("test05_lsb01_removed_saved.bmp");
   image.set_all_ith_bits_low(2);
   image.save_image("test05_lsb012_removed_saved.bmp");
   image.set_all_ith_bits_low(3);
   image.save_image("test05_lsb0123_removed_saved.bmp");
   image.set_all_ith_bits_low(4);
   image.save_image("test05_lsb01234_removed_saved.bmp");
   image.set_all_ith_bits_low(5);
   image.save_image("test05_lsb012345_removed_saved.bmp");
   image.set_all_ith_bits_low(6);
   image.save_image("test05_lsb0123456_removed_saved.bmp");
}

inline void test06()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test06() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   bitmap_image red_channel_image;
   image.export_color_plane(bitmap_image::red_plane,red_channel_image);
   red_channel_image.save_image("test06_red_channel_image.bmp");

   bitmap_image green_channel_image;
   image.export_color_plane(bitmap_image::green_plane,green_channel_image);
   green_channel_image.save_image("test06_green_channel_image.bmp");

   bitmap_image blue_channel_image;
   image.export_color_plane(bitmap_image::blue_plane,blue_channel_image);
   blue_channel_image.save_image("test06_blue_channel_image.bmp");
}

inline void test07()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test07() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   image.convert_to_grayscale();
   image.save_image("test07_grayscale_image.bmp");
}

inline void test08()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test08() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   bitmap_image image1;
   bitmap_image image2;
   bitmap_image image3;
   bitmap_image image4;

   unsigned int w = image.width();
   unsigned int h = image.height();

   if (!image.region(0,0, w / 2, h / 2,image1))
   {
      std::cout << "ERROR: upper_left_image" << std::endl;
   }

   if (!image.region((w - 1) / 2, 0, w / 2, h / 2,image2))
   {
      std::cout << "ERROR: upper_right_image" << std::endl;
   }

   if (!image.region(0,(h - 1) / 2, w / 2, h / 2,image3))
   {
      std::cout << "ERROR: lower_left_image" << std::endl;
   }

   if (!image.region((w - 1) / 2, (h - 1) / 2, w / 2, h / 2,image4))
   {
      std::cout << "ERROR: lower_right_image" << std::endl;
   }

   image1.save_image("test08_upper_left_image.bmp");
   image2.save_image("test08_upper_right_image.bmp");
   image3.save_image("test08_lower_left_image.bmp");
   image4.save_image("test08_lower_right_image.bmp");
}

inline void test09()
{
   const unsigned int dim = 1000;
   bitmap_image image(dim,dim);
   for (unsigned int x = 0; x < dim; ++x)
   {
      for (unsigned int y = 0; y < dim; ++y)
      {
         rgb_store col = jet_colormap[(x + y) % dim];
         image.set_pixel(x,y,col.red,col.green,col.blue);
      }
   }
   image.save_image("test09_color_map_image.bmp");
}

inline void test10()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test10() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   image.invert_color_planes();
   image.save_image("test10_inverted_color_image.bmp");
}

inline void test11()
{
   std::string file_name("image.bmp");
   bitmap_image image(file_name);

   if (!image)
   {
      printf("test11() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   for (unsigned int i = 0; i < 10; ++i)
   {
      image.add_to_color_plane(bitmap_image::red_plane,10);
      image.save_image(std::string("test11_") + static_cast<char>(48 + i) + std::string("_red_inc_image.bmp"));
   }
}

inline void test12()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test12() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   double* y  = new double [image.pixel_count()];
   double* cb = new double [image.pixel_count()];
   double* cr = new double [image.pixel_count()];

   image.export_ycbcr(y,cb,cr);

   for (unsigned int i = 0; i < image.pixel_count(); ++i)
   {
      cb[i] = cr[i] = 0.0;
   }

   image.import_ycbcr(y,cb,cr);
   image.save_image("test12_only_y_image.bmp");

   delete[] y;
   delete[] cb;
   delete[] cr;
}

inline void test13()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test13() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   double* y  = new double [image.pixel_count()];
   double* cb = new double [image.pixel_count()];
   double* cr = new double [image.pixel_count()];

   image.export_ycbcr(y,cb,cr);

   for (unsigned int j = 0; j < 10; ++j)
   {
      for (unsigned int i = 0; i < image.pixel_count(); ++i)
      {
         y[i] += 15.0;
      }
      image.import_ycbcr(y,cb,cr);
      image.save_image(std::string("test13_") + static_cast<char>(48 + j) + std::string("_y_image.bmp"));
   }

   delete[] y;
   delete[] cb;
   delete[] cr;
}

inline void test14()
{
   bitmap_image image(1024,1024);
   image.clear();

   double c1 = 0.9;
   double c2 = 0.5;
   double c3 = 0.3;
   double c4 = 0.7;

   ::srand(0xA5AA5AA5);
   plasma(image,0,0,image.width(),image.height(),c1,c2,c3,c4,3.0,jet_colormap);
   image.save_image("test14_plasma.bmp");
}

inline void test15()
{
   std::string file_name("image.bmp");

   bitmap_image image(file_name);

   if (!image)
   {
      printf("test15() - Error - Failed to open '%s'\n",file_name.c_str());
      return;
   }

   double c1 = 0.9;
   double c2 = 0.5;
   double c3 = 0.3;
   double c4 = 0.7;

   bitmap_image plasma_image(image.width(),image.height());
   plasma(plasma_image,0,0,plasma_image.width(),plasma_image.height(),c1,c2,c3,c4,3.0,jet_colormap);

   bitmap_image temp_image(image);

   temp_image.alpha_blend(0.1, plasma_image);
   temp_image.save_image("test15_alpha_0.1.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.2, plasma_image);
   temp_image.save_image("test15_alpha_0.2.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.3, plasma_image);
   temp_image.save_image("test15_alpha_0.3.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.4, plasma_image);
   temp_image.save_image("test15_alpha_0.4.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.5, plasma_image);
   temp_image.save_image("test15_alpha_0.5.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.6, plasma_image);
   temp_image.save_image("test15_alpha_0.6.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.7, plasma_image);
   temp_image.save_image("test15_alpha_0.7.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.8, plasma_image);
   temp_image.save_image("test15_alpha_0.8.bmp");
   temp_image = image;

   temp_image.alpha_blend(0.9, plasma_image);
   temp_image.save_image("test15_alpha_0.9.bmp");
}

inline void test16()
{
   bitmap_image image(1024,1024);

   double c1 = 0.9;
   double c2 = 0.5;
   double c3 = 0.3;
   double c4 = 0.7;

   plasma(image,0,0,image.width(),image.height(),c1,c2,c3,c4,3.0,jet_colormap);

   image_drawer draw(image);

   draw.pen_width(3);
   draw.pen_color(255,0,0);
   draw.circle(image.width() / 2 + 100, image.height() / 2, 100);

   draw.pen_width(2);
   draw.pen_color(0,255,255);
   draw.ellipse(image.width() / 2, image.height() / 2, 200,350);

   draw.pen_width(1);
   draw.pen_color(255,255,0);
   draw.rectangle(50,50,250,400);

   draw.pen_color(0,255,0);
   draw.rectangle(450,250,850,880);

   image.save_image("test16_image_drawer.bmp");
}

inline void test17()
{
   bitmap_image image(1000,180);
   image_drawer draw(image);
   const rgb_store* colormap[9] = {
                                   autumn_colormap,
                                   copper_colormap,
                                   gray_colormap,
                                   hot_colormap,
                                   hsv_colormap,
                                   jet_colormap,
                                   prism_colormap,
                                   vga_colormap,
                                   yarg_colormap
                                  };

   for (unsigned int i = 0; i < image.width(); ++i)
   {
      for (unsigned int j = 0; j < 9; ++j)
      {
         draw.pen_color(colormap[j][i].red,colormap[j][i].green,colormap[j][i].blue);
         draw.vertical_line_segment(j * 20, (j + 1) * 20, i);
      }
   }
   
   image.save_image("test17_color_maps.bmp");
}

void _2H1V(bitmap_image &image, unsigned char gray, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;
	for (unsigned int y = 0; y < image.height(); ++y)
	{
		r = ((y%2) == 0)? 0xFF0000FF : 0x00FFFF00;
		g = ((y%2) == 0)? 0x0000FFFF : 0xFFFF0000;
		b = ((y%2) == 0)? 0x00FFFF00 : 0xFF0000FF;

		for (unsigned int x = 0; x < image.width(); ++x)
		{
			col.red   = r & gray;
			col.green = g & gray;
			col.blue  = b & gray;

			r = (r>>8) | (r<<24);
			g = (g>>8) | (g<<24);
			b = (b>>8) | (b<<24);
			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"2H1V_%d.bmp",gray);
		image.save_image(str);
	}
}

void _2V1H_E(bitmap_image &image, unsigned char gray, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;
	for (unsigned int y = 0; y < image.height(); ++y)
	{
		r = ((y%4) == 0 || (y%4) == 1)? 0x00FF : 0xFF00;
		g = ((y%4) == 0 || (y%4) == 1)? 0xFF00 : 0x00FF;
		b = ((y%4) == 0 || (y%4) == 1)? 0x00FF : 0xFF00;

		for (unsigned int x = 0; x < image.width(); ++x)
		{
			col.red   = r & gray;
			col.green = g & gray;
			col.blue  = b & gray;

			r = (r>>8) | (r<<8);
			g = (g>>8) | (g<<8);
			b = (b>>8) | (b<<8);
			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"2V1H_E_%d.bmp",gray);
		image.save_image(str);
	}
}

void _2V1H_O(bitmap_image &image, unsigned char gray, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;
	for (unsigned int y = 0; y < image.height(); ++y)
	{
		if(y==0)
		{
			r = 0xFF00;
			g = 0x00FF;
			b = 0xFF00;
		}
		else
		{
			r = ((y%4) == 1 || (y%4) == 2)? 0x00FF : 0xFF00;
			g = ((y%4) == 1 || (y%4) == 2)? 0xFF00 : 0x00FF;
			b = ((y%4) == 1 || (y%4) == 2)? 0x00FF : 0xFF00;
		}

		for (unsigned int x = 0; x < image.width(); ++x)
		{
			col.red   = r & gray;
			col.green = g & gray;
			col.blue  = b & gray;

			r = (r>>8) | (r<<8);
			g = (g>>8) | (g<<8);
			b = (b>>8) | (b<<8);
			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"2V1H_O_%d.bmp",gray);
		image.save_image(str);
	}
}

void _HnWnB(bitmap_image &image,unsigned char line, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			r = ((y%(line*2))<line)? 0xFF : 0x00;
			g = ((y%(line*2))<line)? 0xFF : 0x00;
			b = ((y%(line*2))<line)? 0xFF : 0x00;

			col.red   = r & 0xFF;
			col.green = g & 0xFF;
			col.blue  = b & 0xFF;

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"H%dW%dB.bmp",line,line);
		image.save_image(str);
	}
}

void _VnWnB(bitmap_image &image,unsigned char line, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			r = ((x%(line*2))<line)? 0xFF : 0x00;
			g = ((x%(line*2))<line)? 0xFF : 0x00;
			b = ((x%(line*2))<line)? 0xFF : 0x00;

			col.red   = r & 0xFF;
			col.green = g & 0xFF;
			col.blue  = b & 0xFF;

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"V%dW%dB.bmp",line,line);
		image.save_image(str);
	}
}

void _nxn_Pixel_OnOff(bitmap_image& image,unsigned int nx,unsigned int ny,unsigned char gray,unsigned char gray_2=0, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{

			if( y%(ny*2)<ny ^ x%(nx*2)<nx )
			{
				col.red   = gray;
				col.green = gray;
				col.blue  = gray;
			}
			else
			{
				col.red   = gray_2;
				col.green = gray_2;
				col.blue  = gray_2;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"%dx&d_Pixel_OnOff_%d_%d.bmp",nx,ny,gray,gray_2);
		image.save_image(str);
	}
}

void _nPixel_OnOff(bitmap_image &image,unsigned char gray,unsigned char n, bool save = true)
{
	_nxn_Pixel_OnOff(image,n,n,gray,0,false);

	if(save)
	{
		char str[80];
		sprintf(str,"%dPixel_OnOff_%d.bmp",n,gray);
		image.save_image(str);
	}
}

void _RGBX_Four_Pixel(bitmap_image &image, bool save = true)
{
	unsigned int r,g,b;
	rgb_store col;

	for (unsigned int x = 0; x < image.width(); x+=4)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				switch(i%4)
				{
					case 0:
						col.red   = 255;
						col.green = 0;
						col.blue  = 0;
						break;
					case 1:
						col.red   = 0;
						col.green = 255;
						col.blue  = 0;
						break;
					case 2:
						col.red   = 0;
						col.green = 0;
						col.blue  = 255;
						break;
					case 3:
						col.red   = 0;
						col.green = 0;
						col.blue  = 0;
						break;
					default:
						col.red   = 0;
						col.green = 0;
						col.blue  = 0;
						break;
				}

				image.set_pixel(i+x,y,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"RGBX_Four_Pixel.bmp");
		image.save_image(str);
	}
}

void _Sub_Pixel_OnOff(bitmap_image &image,unsigned char gray, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if( y%2 == 0 )
			{
				col.red   = (x%2 == 0)? gray : 0;
				col.green = (x%2 == 0)? 0 : gray;
				col.blue  = (x%2 == 0)? gray : 0;
			}
			else
			{
				col.red   = (x%2 == 1)? gray : 0;
				col.green = (x%2 == 1)? 0 : gray;
				col.blue  = (x%2 == 1)? gray : 0;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"Sub_Pixe_OnOff_%d.bmp",gray);
		image.save_image(str);
	}
}

void _V_Sub_Pixe_OnOff(bitmap_image &image,unsigned char gray, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			col.red   = (x%2 == 0)? gray : 0;
			col.green = (x%2 == 0)? 0 : gray;
			col.blue  = (x%2 == 0)? gray : 0;

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"V_Sub_Pixe_OnOff_%d.bmp",gray);
		image.save_image(str);
	}
}

void _H_gray_Scale(bitmap_image &image,bool hflip,rgb_store RGB_filter, bool save = true)
{
	//unsigned int r,g,b;
	
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			col.red   = (unsigned char)(RGB_filter.red * ((double)x/(image.width()-1)));
			col.green = (unsigned char)(RGB_filter.green * ((double)x/(image.width()-1)) );
			col.blue  = (unsigned char)(RGB_filter.blue * ((double)x/(image.width()-1)));

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(hflip)
	{
		image.horizontal_flip();
	}

	if(save)
	{
		char str[80];
		sprintf(str,"H_gray_Scale_0x%.2X%.2X%.2X.bmp",RGB_filter.red,RGB_filter.green,RGB_filter.blue);
		image.save_image(str);
	}
}

void _V_gray_Scale(bitmap_image &image,bool vflip,rgb_store RGB_filter, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			col.red   = (unsigned char)(RGB_filter.red * ((double)y/(image.height()-1)));
			col.green = (unsigned char)(RGB_filter.green * ((double)y/(image.height()-1)));
			col.blue  = (unsigned char)(RGB_filter.blue * ((double)y/(image.height()-1)));

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(vflip)
	{
		image.vertical_flip();
	}

	if(save)
	{
		char str[80];
		sprintf(str,"V_gray_Scale_0x%.2X%.2X%.2X.bmp",RGB_filter.red,RGB_filter.green,RGB_filter.blue);
		image.save_image(str);
	}
}

void _H_RGBW_Gray_Scale(bitmap_image &image,bool hflip, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(y<image.height()/4)
			{
				col.red   = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.green = 0;
				col.blue  = 0;
			}
			else if(y<image.height()/4 * 2)
			{
				col.red   = 0;
				col.green = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.blue  = 0;
			}
			else if(y<image.height()/4 * 3)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = (unsigned char)(255 * ((double)x/(image.width()+1)));
			}
			else
			{
				col.red   = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.green = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.blue  = (unsigned char)(255 * ((double)x/(image.width()+1)));
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(hflip)
	{
		image.horizontal_flip();
	}

	if(save)
	{
		image.save_image("H_RGBW_Gray_Scale.bmp");
	}
}

void _H_WRGB_Gray_Scale(bitmap_image &image,bool hflip, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(y<image.height()/4)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  =  (unsigned char)(255 * ((double)x/(image.width()+1)));
			}
			else if(y<image.height()/4 * 2)
			{
				col.red   = 0;
				col.green = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.blue  = 0;
			}
			else if(y<image.height()/4 * 3)
			{
				col.red   = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.green = 0;
				col.blue  = 0;
			}
			else
			{
				col.red   = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.green = (unsigned char)(255 * ((double)x/(image.width()+1)));
				col.blue  = (unsigned char)(255 * ((double)x/(image.width()+1)));
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(hflip)
	{
		image.horizontal_flip();
	}

	if(save)
	{
		image.save_image("H_WRGB_Gray_Scale.bmp");
	}
}

void _V_RGBW_Gray_Scale(bitmap_image &image,bool vflip, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x<image.width()/4)
			{
				col.red   = (unsigned char)(255 * ((double)y/(image.height()+1)));
				col.green = 0;
				col.blue  = 0;
			}
			else if(x<image.width()/4 * 2)
			{
				col.red   = 0;
				col.green = (unsigned char)(255 * ((double)y/(image.height()+1)));
				col.blue  = 0;
			}
			else if(x<image.width()/4 * 3)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = (unsigned char)(255 * ((double)y/(image.height()+1)));
			}
			else
			{
				col.red   = (unsigned char)(255 * ((double)y/(image.height()+1)));
				col.green = (unsigned char)(255 * ((double)y/(image.height()+1)));
				col.blue  = (unsigned char)(255 * ((double)y/(image.height()+1)));
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(vflip)
	{
		image.vertical_flip();
	}

	if(save)
	{
		image.save_image("V_RGBW_Gray_Scale.bmp");
	}
}

void _White_Frame(bitmap_image &image, unsigned char gray = 255, unsigned char n = 1, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x<n || y<n || x>=(image.width()-n) || y>=(image.height()-n))
			{
				col.red   = gray;
				col.green = gray;
				col.blue  = gray;
				
				image.set_pixel(x,y,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"White_Frame_%d_%d.bmp",gray,n);
		image.save_image(str);
	}
}

void _White_Frame_Cross(bitmap_image &image, bool save = true)
{
	//unsigned int r,g,b;
	rgb_store col;
	double rate = ((double)image.height()-1)/(image.width()-1);
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x==0 || y==0 || x==(image.width()-1) || y==(image.height()-1))
			{
				col.red   = 0xFF;
				col.green = 0xFF;
				col.blue  = 0xFF;
			}
			else if(y == (unsigned int)(x*rate) || y == (unsigned int)(x*(-rate)+image.height()-1))
			{
				col.red   = 0xFF;
				col.green = 0xFF;
				col.blue  = 0xFF;
			}
			else
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
			}
			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		image.save_image("White_Frame_Cross.bmp");
	}
}

void _gray_level(bitmap_image &image,rgb_store RGB_gray, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			col.red   = RGB_gray.red;
			col.green = RGB_gray.green;
			col.blue  = RGB_gray.blue;

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"gray_0x%.2X%.2X%.2X.bmp",RGB_gray.red,RGB_gray.green,RGB_gray.blue);
		image.save_image(str);
	}
}

void _inner_outer_Window(bitmap_image &image,rgb_store inner_RGB_gray,rgb_store outer_RGB_gray, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x>(image.width()/4) && x<(image.width()/4*3)
			&& y>(image.height()/4) && y<(image.height()/4*3))
			{
				col.red   = inner_RGB_gray.red;
				col.green = inner_RGB_gray.green;
				col.blue  = inner_RGB_gray.blue;
			}
			else
			{
				col.red   = outer_RGB_gray.red;
				col.green = outer_RGB_gray.green;
				col.blue  = outer_RGB_gray.blue;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"inner_outer_Window_0x%.2X%.2X%.2X_0x%.2X%.2X%.2X.bmp",inner_RGB_gray.red,inner_RGB_gray.green,inner_RGB_gray.blue,outer_RGB_gray.red,outer_RGB_gray.green,outer_RGB_gray.blue);
		image.save_image(str);
	}
}

void _Mosaic(bitmap_image &image,unsigned char h,unsigned char v,unsigned char gray1=255,unsigned char gray2=0, bool save = true)
{
	rgb_store col;
	unsigned int h_count = image.width()/h;
	unsigned int v_count = image.height()/v;

	_nxn_Pixel_OnOff(image,h_count,v_count,gray1,gray2,false);

	if(save)
	{
		char str[80];
		sprintf(str,"Mosaic_%dx%d_0x%.2X_0x%.2X.bmp",h,v,gray2,gray1);
		image.save_image(str);
	}
}

void _quater_gray(bitmap_image &image,unsigned char f_gray,unsigned char b_gray,unsigned char section, bool save = true)
{
	rgb_store col;

	col.red = b_gray;
	col.green = b_gray;
	col.blue = b_gray;
	_gray_level(image,col,false);

	switch(section)
	{
		case 1:
			for (unsigned int x = 0; x < image.width()/2; ++x)
			{
				for (unsigned int y = 0; y < image.height()/2; ++y)
				{
					col.red   = f_gray;
					col.green = f_gray;
					col.blue  = f_gray;

					image.set_pixel(x,y,col.red,col.green,col.blue);
				}
			}
			break;
		case 2:
			for (unsigned int x = image.width()/2; x < image.width(); ++x)
			{
				for (unsigned int y = 0; y < image.height()/2; ++y)
				{
					col.red   = f_gray;
					col.green = f_gray;
					col.blue  = f_gray;

					image.set_pixel(x,y,col.red,col.green,col.blue);
				}
			}
			break;
		case 3:
			for (unsigned int x = 0; x < image.width()/2; ++x)
			{
				for (unsigned int y = image.height()/2; y < image.height(); ++y)
				{
					col.red   = f_gray;
					col.green = f_gray;
					col.blue  = f_gray;

					image.set_pixel(x,y,col.red,col.green,col.blue);
				}
			}
			break;
		case 4:
			for (unsigned int x = image.width()/2; x < image.width(); ++x)
			{
				for (unsigned int y = image.height()/2; y < image.height(); ++y)
				{
					col.red   = f_gray;
					col.green = f_gray;
					col.blue  = f_gray;

					image.set_pixel(x,y,col.red,col.green,col.blue);
				}
			}
			break;
		default:
			for (unsigned int x = 0; x < image.width()/2; ++x)
			{
				for (unsigned int y = 0; y < image.height()/2; ++y)
				{
					col.red   = f_gray;
					col.green = f_gray;
					col.blue  = f_gray;

					image.set_pixel(x,y,col.red,col.green,col.blue);
				}
			}
			break;

	}

	if(save)
	{
		char str[80];
		sprintf(str,"quater_gray_%d_%d.bmp",f_gray,b_gray);
		image.save_image(str);
	}
}

void _cross(bitmap_image &image, rgb_store RGB_gray, bool save = true)
{	
	rgb_store col;

	for (unsigned int y = 0; y < image.height(); ++y)
	{
		col.red   = RGB_gray.red;
		col.green = RGB_gray.green;
		col.blue  = RGB_gray.blue;

		image.set_pixel(image.width()/2,y,col.red,col.green,col.blue);
	}

	for (unsigned int x = 0; x < image.width(); ++x)
	{
		col.red   = RGB_gray.red;
		col.green = RGB_gray.green;
		col.blue  = RGB_gray.blue;

		image.set_pixel(x,image.height()/2,col.red,col.green,col.blue);
	}
		

	if(save)
	{
		char str[80];
		sprintf(str,"cross_0x%.2X%.2X%.2X.bmp",RGB_gray.red,RGB_gray.green,RGB_gray.blue);
		image.save_image(str);
	}
}

void _cross_gray(bitmap_image &image,rgb_store line_gray,rgb_store bg_gray, bool save = true)
{
	_gray_level(image,bg_gray,false);

	_cross(image,line_gray,false);

	if(save)
	{
		char str[80];
		sprintf(str,"cross_gray_0x%.2X%.2X%.2X_0x%.2X%.2X%.2X.bmp",line_gray.red,line_gray.green,line_gray.blue,bg_gray.red,bg_gray.green,bg_gray.blue);
		image.save_image(str);
	}
}

void _TB_cross(bitmap_image &image,unsigned char line_gray,unsigned char bg_gray,bool vflip, bool save = true)
{
	rgb_store col;
	
	_nxn_Pixel_OnOff(image,image.width(),image.height()/2,bg_gray,0,false);

	col.red = line_gray;
	col.green = line_gray;
	col.blue = line_gray;
	_cross(image,col,false);

	if(vflip)
	{
		image.vertical_flip();
	}

	if(save)
	{
		char str[80];
		sprintf(str,"TB_cross_%d.bmp",bg_gray);
		image.save_image(str);
	}
}

void _TCB(bitmap_image &image,unsigned char gray1,unsigned char gray2, bool save = true)
{
	_nxn_Pixel_OnOff(image,image.width(),image.height()/3,gray2,gray1,false);

	if(save)
	{
		char str[80];
		sprintf(str,"TCB_%d_%d.bmp",gray1,gray2);
		image.save_image(str);
	}
}

void _gray_block(bitmap_image &image,unsigned char h,unsigned char v, bool save = true)
{
	rgb_store col;
	col.red   = 0;
	col.green = 0;
	col.blue  = 0;
	_gray_level(image,col,false);
	double length = ((unsigned int)image.width()*image.width())+((unsigned int)image.height()*image.height());

	for (unsigned int x = 0; x < image.width(); x+=image.width()/h)
	{
		for (unsigned int y = 0; y < image.height(); y+=image.height()/v)
		{
			for (unsigned int i = 0; i < image.width()/h-20 && i+x<image.width(); i++)
			{
				for (unsigned int j = 0; j < image.height()/v-20 && j+y<image.height(); j++)
				{
					unsigned char temp = 255 * sqrt(((double)(i+x)*(i+x)+(j+y)*(j+y))/length);
					col.red   = temp;
					col.green = temp;
					col.blue  = temp;

					image.set_pixel(i+x,j+y,col.red,col.green,col.blue);
				}
			}
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"gray_block_%dx%d.bmp",h,v);
		image.save_image(str);
	}
}

void _color_Bar(bitmap_image &image, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x<image.width()/8)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
			}
			else if(x<image.width()/8 * 2)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 255;
			}
			else if(x<image.width()/8 * 3)
			{
				col.red   = 255;
				col.green = 0;
				col.blue  = 0;
			}
			else if(x<image.width()/8 * 4)
			{
				col.red   = 255;
				col.green = 0;
				col.blue  = 255;
			}
			else if(x<image.width()/8 * 5)
			{
				col.red   = 0;
				col.green = 255;
				col.blue  = 0;
			}
			else if(x<image.width()/8 * 6)
			{
				col.red   = 0;
				col.green = 255;
				col.blue  = 255;
			}
			else if(x<image.width()/8 * 7)
			{
				col.red   = 255;
				col.green = 255;
				col.blue  = 0;
			}
			else
			{
				col.red   = 255;
				col.green = 255;
				col.blue  = 255;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"color_Bar.bmp");
		image.save_image(str);
	}
}

void _H_Pattern(bitmap_image &image, bool save = true)
{
	rgb_store col;

	col.red   = 0;
	col.green = 0;
	col.blue  = 0;
	_gray_level(image,col,false);

	for (unsigned int x = 0; x < image.width(); x+=8)
	{
		for (unsigned int y = 0; y < image.height(); y+=16)
		{
			for (unsigned int i = 1; i < 14; i++)
			{
					col.red   = 255;
					col.green = 255;
					col.blue  = 255;

					image.set_pixel(x,i+y,col.red,col.green,col.blue);
					image.set_pixel(x+6,i+y,col.red,col.green,col.blue);
			}
			for (unsigned int i = 0; i < 7; i++)
			{
					col.red   = 255;
					col.green = 255;
					col.blue  = 255;

					image.set_pixel(i+x,y+7,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"H_Pattern.bmp");
		image.save_image(str);
	}
}

void _V_LD_Pattern(bitmap_image &image,unsigned char n,char mode, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x>image.width()/4 && x<image.width()/4*3
			&& ( (y%(image.height()/n*2)<image.height()/n && mode == 'o') ||  (y%(image.height()/n*2)>=image.height()/n && mode == 'e')))
			{
				col.red   = 255;
				col.green = 255;
				col.blue  = 255;
			}
			else
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"LD_Pattern_2x%d_%c.bmp",n,mode);
		image.save_image(str);
	}
}


void _square(bitmap_image &image,unsigned char gray,unsigned char h,unsigned char v, bool save = true)
{
	rgb_store col;

	//col.red = gray;
	//col.green = gray;
	//col.blue = gray;
	//_gray_level(image,col,false);

	unsigned char ht,vt;

	ht = h*2;
	vt = v*2;


	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if( (((x%(image.width()/ht)) == image.width()/ht/2) && (y%(image.height()/vt*2)) > image.height()/vt/2 && (y%(image.height()/vt*2)) <= image.height()/vt/2*3)
			||  (((y%(image.height()/vt)) == image.height()/vt/2) && (x%(image.width()/ht*2)) > image.width()/ht/2 && (x%(image.width()/ht*2)) <= image.width()/ht/2*3) )
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;

				image.set_pixel(x,y,col.red,col.green,col.blue);
			}
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"square_%dx%d_%d.bmp",h,v,gray);
		image.save_image(str);
	}
}

void _diagonal_grayscale(bitmap_image &image, bool vflip, bool save = true)
{
	rgb_store col;
	double rate = ((double)image.height()-1)/(image.width()-1);
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(y > x*rate)
			{
				col.red   = 255 * (double)x/(image.width()-1);
				col.green = 255 * (double)x/(image.width()-1);
				col.blue  = 255 * (double)x/(image.width()-1);
			}
			else
			{
				col.red   = 255 - 255 * (double)x/(image.width()-1);
				col.green = 255 - 255 * (double)x/(image.width()-1);
				col.blue  = 255 - 255 * (double)x/(image.width()-1);
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	if(vflip)
	{
		image.vertical_flip();
	}

	if(save)
	{
		char str[80];
		sprintf(str,"diagonal_grayscale.bmp");
		image.save_image(str);
	}
}

void _eye_pattern(bitmap_image &image,unsigned char h,unsigned char v, bool save = true)
{
	rgb_store col;
	for (unsigned int x=0; x<image.width(); x=x+image.width()/h)
	{
		for (unsigned int y=0; y<image.height(); y=y+image.height()/v)
		{
			for(unsigned int i=0; i<image.width()/h; i++)
			{
				for(unsigned int j=0; j<image.height()/v; j++)
				{		
					if((y/(image.height()/v))%2 == 0)
					{
						if(i<image.width()/h/2)
						{
							col.red   =  255 * (double)i/(image.width()/h/2-1);
							col.green =  255 * (double)i/(image.width()/h/2-1);
							col.blue  =  255 * (double)i/(image.width()/h/2-1);
						}
						else
						{
							col.red   =  (i%(image.width()/h/2/2) < (image.width()/h/2/4))? 0 : 255;
							col.green =  (i%(image.width()/h/2/2) < (image.width()/h/2/4))? 0 : 255;
							col.blue  =  (i%(image.width()/h/2/2) < (image.width()/h/2/4))? 0 : 255;
						}
					}
					else
					{
						if(i>=image.width()/h/2)
						{
							col.red   =  255 - 255 * (double)(i-image.width()/h/2)/(image.width()/h/2-1);
							col.green =  255 - 255 * (double)(i-image.width()/h/2)/(image.width()/h/2-1);
							col.blue  =  255 - 255 * (double)(i-image.width()/h/2)/(image.width()/h/2-1);
						}
						else
						{
							col.red   =  (i%(image.width()/h/2/2) > (image.width()/h/2/4))? 0 : 255;
							col.green =  (i%(image.width()/h/2/2) > (image.width()/h/2/4))? 0 : 255;
							col.blue  =  (i%(image.width()/h/2/2) > (image.width()/h/2/4))? 0 : 255;
						}
					}

					image.set_pixel(i+x,j+y,col.red,col.green,col.blue);
				}
			}
		}
	}
	if(save)
	{
		char str[80];
		sprintf(str,"eye_pattern.bmp");
		image.save_image(str);
	}
}

void _three_in_one(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image image1(image.width(),image.height()/2);
	bitmap_image image2(image.width(),image.height()/2);

	_H_WRGB_Gray_Scale(image1,true,false);

	col.red = 255;
	col.green = 255;
	col.blue = 255;
	_V_gray_Scale(image2,true,col,false);

	image.copy_from(image1,0,0);
	image.copy_from(image2,0,image.height()/2);

	_White_Frame(image,255,1,false);

	if(save)
	{
		char str[80];
		sprintf(str,"three_in_one.bmp");
		image.save_image(str);
	}
}

void _cross_bar(bitmap_image &image, bool save = true)
{
	rgb_store col;

	col.red = 255;
	col.green = 255;
	col.blue = 255;
	_gray_level(image,col,false);
	_White_Frame(image,0,1,false);

	for (unsigned int x = 0; x < image.width(); ++x)
	{
		col.red   = 0;
		col.green = 0;
		col.blue  = 0;

		image.set_pixel(x,image.height()/2-1,col.red,col.green,col.blue);
		image.set_pixel(x,image.height()/2,col.red,col.green,col.blue);

		image.set_pixel(x,image.height()/2-1-66,col.red,col.green,col.blue);
		image.set_pixel(x,image.height()/2+66,col.red,col.green,col.blue);
	}

	for (unsigned int y = 0; y < image.height(); ++y)
	{
		col.red   = 0;
		col.green = 0;
		col.blue  = 0;

		image.set_pixel(image.width()/2-1,y,col.red,col.green,col.blue);
		image.set_pixel(image.width()/2,y,col.red,col.green,col.blue);

		image.set_pixel(image.width()/2-1-66,y,col.red,col.green,col.blue);
		image.set_pixel(image.width()/2+66,y,col.red,col.green,col.blue);
	}

	if(save)
	{
		char str[80];
		sprintf(str,"cross_bar.bmp");
		image.save_image(str);
	}
}


void _zebra(bitmap_image &image, bool save = true)
{
	rgb_store col;

	col.red = 255/2;
	col.green = 255/2;
	col.blue = 255/2;
	_gray_level(image,col,false);

	bitmap_image center(image.width()/2,image.height()/2);
	_nxn_Pixel_OnOff(center,center.width(),image.height()/32,0,255,false);

	image.copy_from(center,image.width()/4,image.height()/4);

	if(save)
	{
		char str[80];
		sprintf(str,"zebra.bmp");
		image.save_image(str);
	}
}

void _Vcolorbar_moasic(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image image1(image.width()/8,image.height()/2);
	bitmap_image image2(image.width(),image.height()/2);

	col.red = 255;
	col.green = 0;
	col.blue = 0;
	_gray_level(image1,col,false);
	image.copy_from(image1,0,0);
	image.copy_from(image1,image.width()/8*5,0);

	col.red = 0;
	col.green = 255;
	col.blue = 0;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/8,0);
	image.copy_from(image1,image.width()/8*6,0);

	col.red = 0;
	col.green = 0;
	col.blue = 255;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/8*2,0);
	image.copy_from(image1,image.width()/8*7,0);

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/8*3,0);

	col.red = 255;
	col.green = 255;
	col.blue = 255;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/8*4,0);

	_Mosaic(image2,8,4,255,0,false);
	
	image.copy_from(image2,0,image.height()/2);

	if(save)
	{
		char str[80];
		sprintf(str,"Vcolorbar_moasic.bmp");
		image.save_image(str);
	}
}

void _frame_hGrayScale(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image center(image.width()/2,image.height()/2);

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	_gray_level(image,col,false);

	col.red = 255;
	col.green = 255;
	col.blue = 255;
	_V_gray_Scale(center,false,col,false);
	
	image.copy_from(center,image.width()/4,image.height()/4);

	if(save)
	{
		char str[80];
		sprintf(str,"frame_hGrayScale.bmp");
		image.save_image(str);
	}
}

void _RGB_H(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image image1(image.width()/3,image.height());

	col.red = 255;
	col.green = 0;
	col.blue = 0;
	_gray_level(image1,col,false);
	image.copy_from(image1,0,0);

	col.red = 0;
	col.green = 255;
	col.blue = 0;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/3,0);

	col.red = 0;
	col.green = 0;
	col.blue = 255;
	_gray_level(image1,col,false);
	image.copy_from(image1,image.width()/3*2,0);

	if(save)
	{
		char str[80];
		sprintf(str,"RGB_H.bmp");
		image.save_image(str);
	}
}

void _B_W_frame(bitmap_image &image, bool save = true)
{
	rgb_store col;

	_Mosaic(image,1,2,255,0,false);
	_White_Frame(image,255,1,false);

	if(save)
	{
		char str[80];
		sprintf(str,"B_W_frame.bmp");
		image.save_image(str);
	}
}

void _BG_PixelOnOff(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image center(image.width()/2,image.height()/2);

	col.red = 0;
	col.green = 255/2;
	col.blue = 255/2;
	_gray_level(image,col,false);

	_nPixel_OnOff(center,255,1,false);
	
	image.copy_from(center,image.width()/4,image.height()/4);

	if(save)
	{
		char str[80];
		sprintf(str,"BG_PixelOnOff.bmp");
		image.save_image(str);
	}
}

void _32_bit_noise(bitmap_image &image, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(x%2 == 0 && y<image.height()/2)
			{
				col.red   = 255 * y/(image.height()/2-1);
				col.green = 0;
				col.blue  = 255 * y/(image.height()/2-1);
			}
			else if(x%2 == 1 && y<image.height()/2)
			{
				col.red   = 0;
				col.green = 255 * y/(image.height()/2-1);
				col.blue  = 0;
			}
			else if(x%2 == 0 && y>=image.height()/2)
			{
				col.red   = 0;
				col.green = 255 * (image.height()-y-1)/(image.height()/2-1);
				col.blue  = 0;
			}
			else if(x%2 == 1 && y>=image.height()/2)
			{
				col.red   = 255 * (image.height()-y-1)/(image.height()/2-1);
				col.green = 0;
				col.blue  = 255 * (image.height()-y-1)/(image.height()/2-1);
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	for (unsigned int x = image.width()/20; x < image.width(); x+=image.width()/10)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			for (unsigned int i = 0; i < 5; i++)
			{
				col.red   = 255;
				col.green = 255;
				col.blue  = 255;
				image.set_pixel(i+x,y,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"32_bit_noise.bmp");
		image.save_image(str);
	}
}

void _V_H_color_bar(bitmap_image &image, bool save = true)
{
	rgb_store col;

	bitmap_image image1(image.width()/2/8,image.height());
	bitmap_image image2(image.width()/2,image.height()/8);

	col.red = 255;
	col.green = 255;
	col.blue = 0;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,0,0);
	image.copy_from(image2,image.width()/2,0);

	col.red = 0;
	col.green = 255;
	col.blue = 255;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8,0);
	image.copy_from(image2,image.width()/2,image.height()/8);

	col.red = 0;
	col.green = 255;
	col.blue = 0;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*2,0);
	image.copy_from(image2,image.width()/2,image.height()/8*2);

	col.red = 255;
	col.green = 0;
	col.blue = 255;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*3,0);
	image.copy_from(image2,image.width()/2,image.height()/8*3);

	col.red = 255;
	col.green = 0;
	col.blue = 0;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*4,0);
	image.copy_from(image2,image.width()/2,image.height()/8*4);

	col.red = 0;
	col.green = 0;
	col.blue = 255;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*5,0);
	image.copy_from(image2,image.width()/2,image.height()/8*5);

	col.red = 255;
	col.green = 255;
	col.blue = 255;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*6,0);
	image.copy_from(image2,image.width()/2,image.height()/8*6);

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	_gray_level(image1,col,false);
	_gray_level(image2,col,false);
	image.copy_from(image1,image.width()/2/8*7,0);
	image.copy_from(image2,image.width()/2,image.height()/8*7);

	if(save)
	{
		char str[80];
		sprintf(str,"V_H_color_bar.bmp");
		image.save_image(str);
	}
}

void _Xtalk_inspection(bitmap_image &image,rgb_store RGB_grayf,rgb_store RGB_grayb, bool save = true)
{
	rgb_store col;

	_gray_level(image,RGB_grayb,false);

	for (unsigned int x = image.width()/4; x < image.width()/4*3; x = x+image.width()/2/19*5)
	{
		for (unsigned int y = image.height()/3; y < image.height()/3+image.height()/4; ++y)
		{
			for (unsigned int i = 0; i < image.width()/2/19*2; i++)
			{
				col.red   = RGB_grayf.red;
				col.green = RGB_grayf.green;
				col.blue  = RGB_grayf.blue;

				image.set_pixel(i+x,y,col.red,col.green,col.blue);
			}

			for (unsigned int i = image.width()/2/19*3; i < image.width()/2/19*4; i++)
			{
				col.red   = RGB_grayf.red;
				col.green = RGB_grayf.green;
				col.blue  = RGB_grayf.blue;

				image.set_pixel(i+x,y,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"Xtalk_inspection_0x%.2X%.2X%.2X_0x%.2X%.2X%.2X.bmp",RGB_grayf.red,RGB_grayf.green,RGB_grayf.blue,RGB_grayb.red,RGB_grayb.green,RGB_grayb.blue);
		image.save_image(str);
	}
}


void _Alignment_Pattern(bitmap_image &image, bool save = true)
{
	rgb_store col;

	col.red   = 0;
	col.green = 0;
	col.blue  = 0;
	_gray_level(image,col,false);

	for (unsigned int x = 0; x<=image.width(); x=x+image.width()/(17-1))
	{
		for (unsigned int y = 0; y<=image.height(); y=y+image.height()/(10-1))
		{
			col.red   = 255;
			col.green = 255;
			col.blue  = 255;
			
			unsigned int ox = (x == image.width())? x-2 : x;
			unsigned int oy = (y == image.height())? y-2 : y;

			image.set_pixel(ox,oy,col.red,col.green,col.blue);			
			image.set_pixel(ox+1,oy,col.red,col.green,col.blue);
			image.set_pixel(ox,oy+1,col.red,col.green,col.blue);
			image.set_pixel(ox+1,oy+1,col.red,col.green,col.blue);
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"Alignment_Pattern.bmp");
		image.save_image(str);
	}
}

void _Black_Block(bitmap_image &image,unsigned char h,unsigned char v, bool save = true)
{
	rgb_store col;
	for (unsigned int x = 0; x < image.width(); ++x)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if( ((x+1)%(image.width()/h))==0 || ((y+1)%(image.height()/v))==0 )
			{
				col.red   = 255;
				col.green = 255;
				col.blue  = 255;
			}
			else
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
			}

			image.set_pixel(x,y,col.red,col.green,col.blue);
		}
	}

	_White_Frame(image,0,1,false);

	if(save)
	{
		char str[80];
		sprintf(str,"Black_Block%dx%d.bmp",h,v);
		image.save_image(str);
	}
}

void _Moasic_Gray(bitmap_image &image,rgb_store RGB_gray, bool save = true)
{
	bitmap_image image1(image.width(),image.height()/2);

	_gray_level(image,RGB_gray,false);
	_Mosaic(image1,8,4,255,0,false);
	image.copy_from(image1,0,0);

	if(save)
	{
		char str[80];
		sprintf(str,"Moasic_Gray_0x%.2X%.2X%.2X.bmp",RGB_gray.red,RGB_gray.green,RGB_gray.blue);
		image.save_image(str);
	}
}


void _RGBW_Gray_Scale_V(bitmap_image &image, bool save = true)
{
	bitmap_image image1(image.width()/4,image.height());

	rgb_store col;

	col.red   = 255;
	col.green = 0;
	col.blue  = 0;
	_V_gray_Scale(image1,false,col,false);
	image.copy_from(image1,0,0);

	col.red   = 0;
	col.green = 255;
	col.blue  = 0;
	_V_gray_Scale(image1,true,col,false);
	image.copy_from(image1,image.width()/4,0);

	col.red   = 0;
	col.green = 0;
	col.blue  = 255;
	_V_gray_Scale(image1,false,col,false);
	image.copy_from(image1,image.width()/4*2,0);

	col.red   = 255;
	col.green = 255;
	col.blue  = 255;
	_V_gray_Scale(image1,true,col,false);
	image.copy_from(image1,image.width()/4*3,0);

	if(save)
	{
		char str[80];
		sprintf(str,"RGBW_Gray_Scale_V.bmp");
		image.save_image(str);
	}
}

void _Oblique_line(bitmap_image &image, rgb_store line, rgb_store bg, bool save = true)
{
	rgb_store col;

	unsigned int xjump = image.height()/7;
	double rate = image.height()/xjump;

	_gray_level(image,bg,false);

	for (unsigned int x = 0; x < image.width(); x++)
	{
		for (unsigned int y = 0; y < image.height(); ++y)
		{
			if(y == x * rate || y == (x%xjump) * rate)
			{
				col.red   = line.red;
				col.green = line.green;
				col.blue  = line.blue;

				image.set_pixel(x,y,col.red,col.green,col.blue);
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"Oblique_line_0x%.2X%.2X%.2X_0x%.2X%.2X%.2X.bmp",line.red,line.green,line.blue,bg.red,bg.green,bg.blue);
		image.save_image(str);
	}
}

void _B_W_line(bitmap_image &image, bool save = true)
{
	rgb_store col;

	col.red   = 255;
	col.green = 255;
	col.blue  = 255;
	_Mosaic(image,1,2,255,0,false);

	for (unsigned int x = 0; x < image.width(); x++)
	{
		image.set_pixel(x,image.height()/5*2,col.red,col.green,col.blue);
	}

	if(save)
	{
		char str[80];
		sprintf(str,"B_W_line.bmp");
		image.save_image(str);
	}
}

void _Merge(bitmap_image &image, bool save = true)
{
	bitmap_image image1(image.width()/2,image.height());

	rgb_store col;

	col.red   = 0;
	col.green = 0;
	col.blue  = 0;
	_nPixel_OnOff(image,255/2,2,false);

	col.red   = 255/2;
	col.green = 255/2;
	col.blue  = 255/2;
	_square(image,255,8,4,false);
	//image.copy_from(image1,image.width()/2,0);


	if(save)
	{
		char str[80];
		sprintf(str,"Two Pixel OnOff(50)+Surface-Pushing pattern(8x4).bmp");
		image.save_image(str);
	}
}

void _half_VAA_custom(bitmap_image &image, bool save = true)
{
	rgb_store col;
	col.red   = 0;
	col.green = 0;
	col.blue  = 0;

	for (unsigned int x = 0; x < image.width(); x++)
	{
		for (unsigned int y = 0; y < image.height(); y++)
		{
			if(y % 2 == 0)
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
				switch(x%4)
				{
					case 0:
						col.red   = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 1:
						col.green = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 2:
						col.blue  = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 3:
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
				}
			}
			else
			{
				col.red   = 0;
				col.green = 0;
				col.blue  = 0;
				switch(x%4)
				{
					case 0:
						col.green = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 1:
						col.blue = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 2:
						//col.red  = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
					case 3:
						col.red  = 255;
						image.set_pixel(x,y,col.red,col.green,col.blue);
						break;
				}
			}
		}
	}

	if(save)
	{
		char str[80];
		sprintf(str,"Half_VAA_custom.bmp");
		image.save_image(str);
	}
}

int main()
{
	const unsigned int w = 3840;
	const unsigned int h = 2160;
	
	//initial
	bitmap_image image(w,h);
	rgb_store col;

	_half_VAA_custom(image);

	//col.red = 0;
	//col.green = 0;
	//col.blue = 0;
	//_gray_level(image,col,false);

	//draw picture
	//_HnWnB(image,16);
	//_VnWnB(image,16);
	//_RGBX_Four_Pixel(image);
	//_2H1V(image,255/2);
	//_2V1H_E(image);
	//_2V1H_O(image);
	//_nPixel_OnOff(image,255/2,2);
	//_Sub_Pixel_OnOff(image,255);
	
	//col.red = 255/8;
	//col.green = 255/8;
	//col.blue = 255/8;
	//_H_gray_Scale(image,false,col);

	//col.red = 255/8;
	//col.green = 255/8;
	//col.blue = 255/8;
	//_V_gray_Scale(image,false,col);

	//_H_RGBW_Gray_Scale(image,false);
	//_V_RGBW_Gray_Scale(image,false);

	//col.red = 255*17/100;
	//col.green = 255*17/100;
	//col.blue = 255*17/100;
	//_gray_level(image,col,false);
	//_White_Frame(image,255/4,1);

	//_White_Frame_Cross(image);
	
	//col.red = 0;
	//col.green = 0;
	//col.blue = 255*75/100;
	//_gray_level(image,col);

	//rgb_store in,out;
	//in.red = 0;
	//in.green = 0;
	//in.blue = 0;
	//out.red = 255;
	//out.green = 255;
	//out.blue= 255;
	//_inner_outer_Window(image,in,out);

	//_V_Sub_Pixe_OnOff(image,128);
	//_Mosaic(image,2,2,255);
	//_quater_gray(image,255,0,4);
	//_cross(image,255,'W');

	//rgb_store line,bg;
	//line.red = 255;
	//line.green = 255;
	//line.blue = 255;
	//bg.red = 0;
	//bg.green = 255/4;
	//bg.blue= 0;
	//_cross_gray(image,line,bg);

	//_TB_cross(image,255,255,true);
	//_TCB(image,255,0);
	//_gray_block(image,16,16);
	//_color_Bar(image);
	//_H_Pattern(image);
	//_V_LD_Pattern(image,16,'o');
	//_square(image,255,12,8);
	//_diagonal_grayscale(image,false);
	//_eye_pattern(image,8,8);
	//_three_in_one(image);
	//_cross_bar(image);
	//_zebra(image);
	//_Vcolorbar_moasic(image);
	//_frame_hGrayScale(image);
	//_RGB_H(image);
	//_B_W_frame(image);
	//_BG_PixelOnOff(image);
	//_32_bit_noise(image);
	//_V_H_color_bar(image);

	//rgb_store in,out;
	//in.red = 0;
	//in.green = 0;
	//in.blue = 0;
	//out.red = 255/2;
	//out.green = 255/2;
	//out.blue= 255/2;
	//_Xtalk_inspection(image,in,out);
	//_Alignment_Pattern(image);
	//_Black_Block(image,5,5);

	//col.red = 255/2;
	//col.green = 255/2;
	//col.blue = 255/2;
	//_Moasic_Gray(image,col);
	//_RGBW_Gray_Scale_V(image);

	//rgb_store line,bg;
	//line.red = 255;
	//line.green = 255;
	//line.blue = 255;
	//bg.red = 255*32/100;
	//bg.green = 255*32/100;
	//bg.blue= 255*32/100;
	//_Oblique_line(image,line,bg);
	//_B_W_line(image);
	//_Merge(image);

	

	return 0;
}

