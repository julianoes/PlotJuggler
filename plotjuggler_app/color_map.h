#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#include <map>
#include <QColor>
#include "sol.hpp"

class ColorMap
{
public:
  using Ptr = std::shared_ptr<ColorMap>;

  sol::protected_function_result setScrip(QString script);

  QString script() const
  {
    return _script;
  }

  QColor mapColor(double value) const;

  QString getError(sol::error err) const;

private:
  sol::state _lua_engine;
  sol::protected_function _lua_function;
  QString _script;
};


// Storing ColoMaps as a "singleton"
std::map<QString, ColorMap::Ptr>& ColorMapLibrary();
void SaveColorMapToSettings();
void LoadColorMapFromSettings();


#endif // COLOR_MAP_H
