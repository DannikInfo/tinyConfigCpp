#include "config.h"

nlohmann::json config::j;
nlohmann::json config::preJ;
bool config::loaded = false;
std::string config::configName;

void config::init(const std::string &fName){
    configName = fName;
}

void config::loadConfig(){
    if(std::filesystem::exists(configName+".json")){
        std::ifstream i(configName+".json");
        i >> preJ;
        //Check new paths in defaults
        bool found = false;
        if(!j.empty()) {
            for (auto &[key, value]: j.items()) {
                if (!preJ.contains(key)) {
                    preJ[key] = value;
                    found = true;
                }
            }
            j = preJ;
            if (found){
                saveConfig();
            }
        }
        i.close();
    }else
        saveConfig();
    loaded = true;
}

void config::saveConfig(){
    std::ofstream o(configName+".json");
    o << std::setw(4) << j << std::endl;
    o.close();
}