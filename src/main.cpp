#include <exiv2/exiv2.hpp>
#include <iostream>

int main(int args, char** argv) {
	//std::string image_path = "../sampledata/0000.jpg";
	std::string image_path = "../sampledata/0000.jpg";

	try {
		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(image_path);
		image->readMetadata();

		Exiv2::ExifData& exif_data = image->exifData();
		if (exif_data.empty()) {
			std::cout << "No exif data" << std::endl;
			return 1;
		}

		Exiv2::ExifData::const_iterator end = exif_data.end();
		for (Exiv2::ExifData::const_iterator it = exif_data.begin(); it != end; ++it) {
			//const char* tn = it->typeName();
			//std::cout << it->key() << " , " << it->tag() << " , " << (tn ? tn : "Unknown") << ", " << it->count() << ", " << it->value() << std::endl;
			std::cout << it->key() << " : " << it->value() << std::endl;
		}
	}
	catch (Exiv2::Error& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
