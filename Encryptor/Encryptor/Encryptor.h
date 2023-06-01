#pragma once

const std::string key = "TypeCDump";

std::string encrypt(std::string msg, std::string key);
std::string decrypt(std::string msg, std::string key);