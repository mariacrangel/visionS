#ifndef BASE64_H
#define BASE64_H

#include <cassert>

#include <opencv2/core/cvstd.hpp>
#include <opencv2/opencv.hpp>


#include <iostream>
#include "opencv2/core/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <string>

/*

 Conversiones base64 - Mat(opencv) y biceversa para enviar imagenes por mqtt

*/


/**
 * @brief Encodes a opencv mat to a base64 string with added metadata for the browser
 * @param frame Mat frame to be encoded
 * @return Encoded mat to string
 */
std::string encode_image(cv::Mat &frame);

/**
 * @brief Resizes and encodes to base64 for the browser
 * @param frame Mat frame to be encoded
 * @param size Size for which the frame is going to be resized
 * @return Encoded string
 */
std::string encode_image(cv::Mat &frame, cv::Size size);

/**
 * @brief Decode base64 string to a Mat matrix
 * @param Encoded image to matrix.
 * @return Decoded image.
 */
cv::Mat decode_image_to_mat(std::string const &encoded);

/**
 * @brief Decode a base64 string.
 * Decodes a base64 string, if metadata is set it will remove the header
 * needed for the browser.
 * @param Encoded encoded string
 * @return Decoded Mat as string
 */
std::string decode_image_to_string(std::string const &encoded);

/* Should not be used */
std::string base64_decode(std::string const &encoded_string);
std::string base64_encode(unsigned char const *bytes_to_encode,
                          unsigned int len);
std::string base64_encode(const std::string &to_encode);
#endif // BASE64_H
