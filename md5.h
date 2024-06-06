/** 
* @file md5.h
* @author Чумаков М.Д.
* @version 1.0
* @date 01.05.2024
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля md5
*/

#include <iostream>
#include <vector>

#include <cryptopp/hex.h> 

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h> 

std::string MD5_hash(std::string msg);
