#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include "json.hpp"

class config {
private:
    static nlohmann::json j;
    static nlohmann::json preJ;
    static bool loaded;
    static std::string configName;
public:

    static void init(const std::string &fName);
    static void loadConfig();
    static void saveConfig();

    /**
     * Get value on key in config
     * @tparam T - type
     * @param key - config Path
     * @return - value with T type
     */
    template<typename T>
    static T get(const std::string& key) {
        return j[key].get<T>();
    }

    /**
     * Get value on key in config, if not exists set default value
     * @tparam T - type
     * @param key - config path
     * @param value - default value
     * @return - value with T type, if not exists in config - default value;
     */
    template<typename T>
    static T get(std::string key, T value) {
        if(!j.contains(key))
            set(key, value);
        return j[key].get<T>();
    }

    /**
     * Set value on key in config.
     * @tparam T - type
     * @param key - config path
     * @param value - value
     */
    template<typename T>
    static void set(const std::string& key, T value) {
        j[key] = value;
        if(!j.contains(key) && loaded)
            saveConfig();
    }

};
#endif //CONFIG_H