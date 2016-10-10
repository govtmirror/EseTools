// config.h
//
// Class for esegend(8) configuration.
//
// (C) Copyright 2016 Fred Gleason <fredg@paravelsystems.com>
//     All Rights Reserved.
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

#define ESEGEND_CONF_FILE "/etc/esegend.conf"
#define ESEGEND_DEFAULT_HOUR_MODE Config::Hour12
#define ESEGEND_DEFAULT_ALSA_DEVICE "hw:0"
#define ESEGEND_DEFAULT_ALSA_FORMAT "AUTO"
#define ESEGEND_DEFAULT_SAMPLE_RATE 192000
#define ESEGEND_DEFAULT_CHANNELS 1
#define ESEGEND_DEFAULT_PERIOD_QUANTITY 3

class Config
{
 public:
  enum HourMode {Hour12=12,Hour24=24};
  Config();
  HourMode hourMode() const;
  void setHourMode(HourMode mode);
  QString alsaDevice() const;
  void setAlsaDevice(const QString &str);
  unsigned alsaFormat() const;
  void setAlsaFormat(unsigned fmt);
  unsigned sampleRate() const;
  void setSampleRate(unsigned samprate);
  unsigned channels() const;
  void setChannels(unsigned chans);
  unsigned periodQuantity() const;
  void setPeriodQuantity(unsigned periods);
  void load();
  void save() const;

 private:
  HourMode config_hour_mode;
  QString config_alsa_device;
  unsigned config_alsa_format;
  unsigned config_sample_rate;
  unsigned config_channels;
  unsigned config_period_quantity;
};


#endif  // CONFIG_H
