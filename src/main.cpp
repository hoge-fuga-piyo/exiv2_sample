#include <exiv2/exiv2.hpp>
#include <iostream>

int main(int args, char** argv) {
	std::string image_path = "../sampledata/0000.jpg";

	try {
		// v0.27.2-RC3以前はAutoPtrが返り値、2019/7/21現在の最新masterブランチではunique_ptr<Exiv2::Image>が返り値になっている。
		// C++17でauto_ptrが削除されたからと思われる。
		//Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(image_path);
		std::unique_ptr<Exiv2::Image> image = Exiv2::ImageFactory::open(image_path);
		image->readMetadata();

		Exiv2::ExifData& exif_data = image->exifData();
		if (exif_data.empty()) {
			std::cout << "No exif data" << std::endl;
			return 1;
		}

		// タグの存在確認
		//auto itr = exif_data.findKey(Exiv2::ExifKey("Exif.Photo.FocalPlaneXResolution"));
		auto itr = exif_data.findKey(Exiv2::ExifKey("Exif.Photo.FocalLength"));
		if (itr != exif_data.end()) {
			std::cout << "Tag is exist" << std::endl;
		}
		else {
			std::cout << "Tag is not exist" << std::endl;
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
