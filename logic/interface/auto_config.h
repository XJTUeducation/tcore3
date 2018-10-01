#ifndef __auto_config_h__
#define __auto_config_h__
// tools from sisyphus 
#include <map>
#include <string>

#include "tools.h"
#include "tinyxml/tinyxml.h"

using namespace tools;
using namespace std;

struct oResource {
/*��ԴID*/
    int _id;
/*��������
1:�Լ�
2:�з�
3:����
4.������*/
    int _type;
/*�Ƿ�ѭ��ִ��
0:��ѭ��
1:ѭ��*/
    int _loop;
/*��������
��û���
��λ����
���loopѡ��Ϊ��ѭ��,���ѡ������,
�ڶ���ִ�����֮�����*/
    int _life_cycle;
};
struct oSkillAction {
/*������*/
    string _action;
/*����
1:�Լ�ִ�ж���
2:�з�ִ�ж���
3:����ִ�ж���*/
    int _type;
/*�Ƿ�ѭ��ִ��
0:��ѭ��
1:ѭ��*/
    int _loop;
};
struct oSkillBuff {
/*buffid*/
    int _buff;
/*��������
1:�Լ�
2:�з�
3:����
4.������
5.·��*/
    int _type;
};
struct o_config_advertise {
/*����id*/
    int _id;
/*��������
0.���
1.��Ƭ
2.ʳ��*/
    int _type;
/*��������*/
    int _param;
/*��������*/
    int _number;
};
extern std::map<int, o_config_advertise> g_config_advertise_map;
inline void init_config_advertise(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "advertise.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * advertise = root->FirstChildElement("advertise");
    while(advertise) {
        o_config_advertise oadvertise;
        oadvertise._id = tools::stringAsInt(advertise->Attribute("id"));
        oadvertise._type = tools::stringAsInt(advertise->Attribute("type"));
        oadvertise._param = tools::stringAsInt(advertise->Attribute("param"));
        oadvertise._number = tools::stringAsInt(advertise->Attribute("number"));
        advertise = advertise->NextSiblingElement("advertise");
        g_config_advertise_map.insert(std::make_pair(oadvertise._id, oadvertise));
    }
}

struct o_config_buff {
/*buff��id*/
    int _id;
/*buff����:
0:�ı�����
1:����
2:������ײ
3.����*/
    int _type;
/*��������:
0:����*/
    int _attr_type;
/*��buff����Ϊ�ı�����ʱ��Ч
delay��ÿ�ʼ�޸�����
��λ����*/
    int _delay;
/*buff����ʱ��
����
-1.����*/
    int _period;
/*�޸����Լ��,
��λ����*/
    int _interval;
/*�޸����Դ���*/
    int _count;
/*ÿ���޸����Ե�ֵ
���ذ��ٷֱ��޸�*/
    float _value;
/*ȥ��buff����������
0.��
1.��ɫ�󷽼����¶���*/
    string _cancel;
/*buff����*/
    string _des;
/*��Դ*/
    vector<int> _resource;
};
extern std::map<int, o_config_buff> g_config_buff_map;
inline void init_config_buff(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "buff.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * buff = root->FirstChildElement("buff");
    while(buff) {
        o_config_buff obuff;
        obuff._id = tools::stringAsInt(buff->Attribute("id"));
        obuff._type = tools::stringAsInt(buff->Attribute("type"));
        obuff._attr_type = tools::stringAsInt(buff->Attribute("attr_type"));
        obuff._delay = tools::stringAsInt(buff->Attribute("delay"));
        obuff._period = tools::stringAsInt(buff->Attribute("period"));
        obuff._interval = tools::stringAsInt(buff->Attribute("interval"));
        obuff._count = tools::stringAsInt(buff->Attribute("count"));
        obuff._value = tools::stringAsFloat(buff->Attribute("value"));
        obuff._cancel = buff->Attribute("cancel");
        obuff._des = buff->Attribute("des");
        {
            std::string str = buff->Attribute("resource");
            tools::osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                int value = tools::stringAsInt(arrays[i].c_str());
                obuff._resource.push_back(value);
            }
        }
        buff = buff->NextSiblingElement("buff");
        g_config_buff_map.insert(std::make_pair(obuff._id, obuff));
    }
}

struct o_config_food {
/*id*/
    int _id;
/*����*/
    string _name;
/*���ӵľ���ֵ*/
    int _exp;
/*��Դ*/
    int _res;
/*����*/
    int _dsc;
};
extern std::map<int, o_config_food> g_config_food_map;
inline void init_config_food(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "food.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * food = root->FirstChildElement("food");
    while(food) {
        o_config_food ofood;
        ofood._id = tools::stringAsInt(food->Attribute("id"));
        ofood._name = food->Attribute("name");
        ofood._exp = tools::stringAsInt(food->Attribute("exp"));
        ofood._res = tools::stringAsInt(food->Attribute("res"));
        ofood._dsc = tools::stringAsInt(food->Attribute("dsc"));
        food = food->NextSiblingElement("food");
        g_config_food_map.insert(std::make_pair(ofood._id, ofood));
    }
}

struct o_global_config {
/*��ɫ����CDʱ��(��)*/
    int _create_role_timer_interval;
/*��ɫͳһ�ƶ��ٶ�*/
    int _move_speed;
/*����ʿ����cdʱ��(����)*/
    int _public_cd;
/*��Ϸ���ڽ�ɫ���д�С*/
    int _role_queue_size;
/*����ʱ�����룩*/
    int _game_time;
/*��ʼ��ɫ*/
    string _init_role;
/*����ս��ɫ��*/
    int _max_role_fighting;
/*ˢ���̳ǻ�������*/
    int _shop_refresh_cost_base;
/*ˢ���̳ǵ�������*/
    int _shop_refresh_cost_up;
/*ˢ���̳�������*/
    int _shop_refresh_cost_max;
/*ˢ���̳���Ʒ��*/
    int _shop_refresh_number;
/*ˢ���̳�
�������*/
    int _shop_refresh_interval;
/*��潱�����*/
    int _advertise_interval;
/*ÿ�չ�潱������*/
    int _advertise_daily_count;
};
extern o_global_config g_global_config;
inline void init_global_config(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "global.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * global = root->FirstChildElement("global");
    if (global) {
        g_global_config._create_role_timer_interval = tools::stringAsInt(global->Attribute("create_role_timer_interval"));
        g_global_config._move_speed = tools::stringAsInt(global->Attribute("move_speed"));
        g_global_config._public_cd = tools::stringAsInt(global->Attribute("public_cd"));
        g_global_config._role_queue_size = tools::stringAsInt(global->Attribute("role_queue_size"));
        g_global_config._game_time = tools::stringAsInt(global->Attribute("game_time"));
        g_global_config._init_role = global->Attribute("init_role");
        g_global_config._max_role_fighting = tools::stringAsInt(global->Attribute("max_role_fighting"));
        g_global_config._shop_refresh_cost_base = tools::stringAsInt(global->Attribute("shop_refresh_cost_base"));
        g_global_config._shop_refresh_cost_up = tools::stringAsInt(global->Attribute("shop_refresh_cost_up"));
        g_global_config._shop_refresh_cost_max = tools::stringAsInt(global->Attribute("shop_refresh_cost_max"));
        g_global_config._shop_refresh_number = tools::stringAsInt(global->Attribute("shop_refresh_number"));
        g_global_config._shop_refresh_interval = tools::stringAsInt(global->Attribute("shop_refresh_interval"));
        g_global_config._advertise_interval = tools::stringAsInt(global->Attribute("advertise_interval"));
        g_global_config._advertise_daily_count = tools::stringAsInt(global->Attribute("advertise_daily_count"));
    }
}

struct o_config_level {
/*�ȼ�*/
    int _level;
/*�ܾ���*/
    int _total_exp;
/*������һ������*/
    int _exp;
};
extern std::map<int, o_config_level> g_config_level_map;
inline void init_config_level(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "level.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * level = root->FirstChildElement("level");
    while(level) {
        o_config_level olevel;
        olevel._level = tools::stringAsInt(level->Attribute("level"));
        olevel._total_exp = tools::stringAsInt(level->Attribute("total_exp"));
        olevel._exp = tools::stringAsInt(level->Attribute("exp"));
        level = level->NextSiblingElement("level");
        g_config_level_map.insert(std::make_pair(olevel._level, olevel));
    }
}

struct o_config_map {
/*��ͼid*/
    int _id;
/*·����*/
    int _path_count;
/*·�߳���*/
    int _path_length;
/*��Դ*/
    string _res;
};
extern std::map<int, o_config_map> g_config_map_map;
inline void init_config_map(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "map.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * map = root->FirstChildElement("map");
    while(map) {
        o_config_map omap;
        omap._id = tools::stringAsInt(map->Attribute("id"));
        omap._path_count = tools::stringAsInt(map->Attribute("path_count"));
        omap._path_length = tools::stringAsInt(map->Attribute("path_length"));
        omap._res = map->Attribute("res");
        map = map->NextSiblingElement("map");
        g_config_map_map.insert(std::make_pair(omap._id, omap));
    }
}

struct o_config_match {
/*���*/
    int _id;
/*��С������*/
    int _cup_min;
/*��󽱱���*/
    int _cup_max;
};
extern std::map<int, o_config_match> g_config_match_map;
inline void init_config_match(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "match.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * match = root->FirstChildElement("match");
    while(match) {
        o_config_match omatch;
        omatch._id = tools::stringAsInt(match->Attribute("id"));
        omatch._cup_min = tools::stringAsInt(match->Attribute("cup_min"));
        omatch._cup_max = tools::stringAsInt(match->Attribute("cup_max"));
        match = match->NextSiblingElement("match");
        g_config_match_map.insert(std::make_pair(omatch._id, omatch));
    }
}

struct o_config_piece {
/*id*/
    int _id;
/*����*/
    string _name;
/*�ϳɽ�ɫid*/
    int _role;
/*��Դ*/
    int _res;
/*����*/
    int _dsc;
};
extern std::map<int, o_config_piece> g_config_piece_map;
inline void init_config_piece(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "piece.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * piece = root->FirstChildElement("piece");
    while(piece) {
        o_config_piece opiece;
        opiece._id = tools::stringAsInt(piece->Attribute("id"));
        opiece._name = piece->Attribute("name");
        opiece._role = tools::stringAsInt(piece->Attribute("role"));
        opiece._res = tools::stringAsInt(piece->Attribute("res"));
        opiece._dsc = tools::stringAsInt(piece->Attribute("dsc"));
        piece = piece->NextSiblingElement("piece");
        g_config_piece_map.insert(std::make_pair(opiece._id, opiece));
    }
}

struct o_config_random_shop {
/*���*/
    int _id;
/*��Ʒ���
0.��Ƭ
1.ʳ��*/
    int _type;
/*��Ʒid*/
    int _content_id;
/*�ɹ�������*/
    int _number;
/*����*/
    int _cost;
};
extern std::map<int, o_config_random_shop> g_config_random_shop_map;
inline void init_config_random_shop(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "random_shop.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * random_shop = root->FirstChildElement("random_shop");
    while(random_shop) {
        o_config_random_shop orandom_shop;
        orandom_shop._id = tools::stringAsInt(random_shop->Attribute("id"));
        orandom_shop._type = tools::stringAsInt(random_shop->Attribute("type"));
        orandom_shop._content_id = tools::stringAsInt(random_shop->Attribute("content_id"));
        orandom_shop._number = tools::stringAsInt(random_shop->Attribute("number"));
        orandom_shop._cost = tools::stringAsInt(random_shop->Attribute("cost"));
        random_shop = random_shop->NextSiblingElement("random_shop");
        g_config_random_shop_map.insert(std::make_pair(orandom_shop._id, orandom_shop));
    }
}

struct o_config_rank {
/*�ƺ�id*/
    int _id;
/*�ƺ�����*/
    string _name;
/*��Ӧ��ͼ*/
    int _map;
/*���轱����*/
    int _cups;
};
extern std::map<int, o_config_rank> g_config_rank_map;
inline void init_config_rank(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "rank.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * rank = root->FirstChildElement("rank");
    while(rank) {
        o_config_rank orank;
        orank._id = tools::stringAsInt(rank->Attribute("id"));
        orank._name = rank->Attribute("name");
        orank._map = tools::stringAsInt(rank->Attribute("map"));
        orank._cups = tools::stringAsInt(rank->Attribute("cups"));
        rank = rank->NextSiblingElement("rank");
        g_config_rank_map.insert(std::make_pair(orank._id, orank));
    }
}

struct o_config_resource {
/*Ψһid
1-.��ɫ�ļ�
2-.��ɫicon
3-.��Ч*/
    int _id;
/*����
0.ͼƬ
1.spine�ļ�
2.������Ч*/
    int _type;
/*��Դ·��
(ע�ⲻҪ��׺��)
�����ͨ��type������Ӻ�׺��*/
    string _res;
/*��������(ֻ��spine������Ҫ):
����ΪĬ��default*/
    string _actionname;
/*�Ƿ�ѭ��*/
    string _loop;
/*�㼶*/
    int _zorder;
};
extern std::map<int, o_config_resource> g_config_resource_map;
inline void init_config_resource(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "resource.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * resource = root->FirstChildElement("resource");
    while(resource) {
        o_config_resource oresource;
        oresource._id = tools::stringAsInt(resource->Attribute("id"));
        oresource._type = tools::stringAsInt(resource->Attribute("type"));
        oresource._res = resource->Attribute("res");
        oresource._actionname = resource->Attribute("actionname");
        oresource._loop = resource->Attribute("loop");
        oresource._zorder = tools::stringAsInt(resource->Attribute("zorder"));
        resource = resource->NextSiblingElement("resource");
        g_config_resource_map.insert(std::make_pair(oresource._id, oresource));
    }
}

struct o_config_role {
/*��ɫid*/
    int _id;
/*����*/
    string _name;
/*��Դ*/
    int _res;
/*��Դ*/
    int _icon_res;
/*��Ƭid*/
    int _piece_id;
/*��Ƭ����*/
    int _piece_number;
/*����
-1.�޼���*/
    int _skill;
/*��������*/
    float _base_weight;
/*������������*/
    float _up_weight;
/*�������*/
    int _strength;
/*��С*/
    float _size;
/*������Ч*/
    string _appear_sound;
/*����*/
    string _dsc;
};
extern std::map<int, o_config_role> g_config_role_map;
inline void init_config_role(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "role.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * role = root->FirstChildElement("role");
    while(role) {
        o_config_role orole;
        orole._id = tools::stringAsInt(role->Attribute("id"));
        orole._name = role->Attribute("name");
        orole._res = tools::stringAsInt(role->Attribute("res"));
        orole._icon_res = tools::stringAsInt(role->Attribute("icon_res"));
        orole._piece_id = tools::stringAsInt(role->Attribute("piece_id"));
        orole._piece_number = tools::stringAsInt(role->Attribute("piece_number"));
        orole._skill = tools::stringAsInt(role->Attribute("skill"));
        orole._base_weight = tools::stringAsFloat(role->Attribute("base_weight"));
        orole._up_weight = tools::stringAsFloat(role->Attribute("up_weight"));
        orole._strength = tools::stringAsInt(role->Attribute("strength"));
        orole._size = tools::stringAsFloat(role->Attribute("size"));
        orole._appear_sound = role->Attribute("appear_sound");
        orole._dsc = role->Attribute("dsc");
        role = role->NextSiblingElement("role");
        g_config_role_map.insert(std::make_pair(orole._id, orole));
    }
}

struct o_config_rule {
/*id*/
    int _id;
/*��ʼʱ��*/
    int _begin;
/*����ʱ��*/
    int _end;
/*����������ֵ*/
    int _max_rand;
};
extern std::map<int, o_config_rule> g_config_rule_map;
inline void init_config_rule(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "rule.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * rule = root->FirstChildElement("rule");
    while(rule) {
        o_config_rule orule;
        orule._id = tools::stringAsInt(rule->Attribute("id"));
        orule._begin = tools::stringAsInt(rule->Attribute("begin"));
        orule._end = tools::stringAsInt(rule->Attribute("end"));
        orule._max_rand = tools::stringAsInt(rule->Attribute("max_rand"));
        rule = rule->NextSiblingElement("rule");
        g_config_rule_map.insert(std::make_pair(orule._id, orule));
    }
}

struct o_config_sceneeffect {
/*����id*/
    int _id;
/*Ч������:
0:��������
1:����ȫ����*/
    int _type;
/**/
    vector<oResource> _view;
/*����ʱ��
����*/
    int _time;
};
extern std::map<int, o_config_sceneeffect> g_config_sceneeffect_map;
inline void init_config_sceneeffect(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "sceneeffect.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * sceneeffect = root->FirstChildElement("sceneeffect");
    while(sceneeffect) {
        o_config_sceneeffect osceneeffect;
        osceneeffect._id = tools::stringAsInt(sceneeffect->Attribute("id"));
        osceneeffect._type = tools::stringAsInt(sceneeffect->Attribute("type"));
        {
            std::string str = sceneeffect->Attribute("view");
            osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                osplitres values;
                tools::split(arrays[i], ",", values);
                oResource value;
                value._id = tools::stringAsInt(values[0].c_str());
                value._type = tools::stringAsInt(values[1].c_str());
                value._loop = tools::stringAsInt(values[2].c_str());
                value._life_cycle = tools::stringAsInt(values[3].c_str());
                osceneeffect._view.push_back(value);
            }
        }
        osceneeffect._time = tools::stringAsInt(sceneeffect->Attribute("time"));
        sceneeffect = sceneeffect->NextSiblingElement("sceneeffect");
        g_config_sceneeffect_map.insert(std::make_pair(osceneeffect._id, osceneeffect));
    }
}

struct o_config_skill {
/*����id*/
    int _id;
/*��������:
0:��buff
1:������ɫ
2:�����Լ�*/
    int _type;
/*ʩ������:
0:Ĭ��ʩ��
1:��������ʩ��
2:��������ʩ��
3:ֱ�ӽӴ���������ʩ��
4:ֱ�ӽӴ���������ʩ��
5:�з�����ֻ��һ��*/
    int _advantage_or_inferiority;
/*ʩ������:
1:��������ʩ��
2:��������ʩ��
3:��������ʩ��*/
    int _cast_type;
/*���õ�λ
1.�Լ�
2.�����м�������
3.�����ез�����
4.�з������һ��
5.������������
6.�Լ��͵з������һ��*/
    int _cast_target;
/*cast_delay������ʱʩ��ʱ��,��λ����*/
    int _cast_delay;
/*��������*/
    string _name;
/*������Ч*/
    string _sound;
/*��������*/
    string _des;
/*��Ч*/
    vector<oResource> _res;
/*����*/
    vector<oSkillAction> _action;
/*buff*/
    vector<oSkillBuff> _buff;
/*������Ч*/
    vector<int> _scene_effect;
};
extern std::map<int, o_config_skill> g_config_skill_map;
inline void init_config_skill(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "skill.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * skill = root->FirstChildElement("skill");
    while(skill) {
        o_config_skill oskill;
        oskill._id = tools::stringAsInt(skill->Attribute("id"));
        oskill._type = tools::stringAsInt(skill->Attribute("type"));
        oskill._advantage_or_inferiority = tools::stringAsInt(skill->Attribute("advantage_or_inferiority"));
        oskill._cast_type = tools::stringAsInt(skill->Attribute("cast_type"));
        oskill._cast_target = tools::stringAsInt(skill->Attribute("cast_target"));
        oskill._cast_delay = tools::stringAsInt(skill->Attribute("cast_delay"));
        oskill._name = skill->Attribute("name");
        oskill._sound = skill->Attribute("sound");
        oskill._des = skill->Attribute("des");
        {
            std::string str = skill->Attribute("res");
            osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                osplitres values;
                tools::split(arrays[i], ",", values);
                oResource value;
                value._id = tools::stringAsInt(values[0].c_str());
                value._type = tools::stringAsInt(values[1].c_str());
                value._loop = tools::stringAsInt(values[2].c_str());
                value._life_cycle = tools::stringAsInt(values[3].c_str());
                oskill._res.push_back(value);
            }
        }
        {
            std::string str = skill->Attribute("action");
            osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                osplitres values;
                tools::split(arrays[i], ",", values);
                oSkillAction value;
                value._action = values[0].c_str();
                value._type = tools::stringAsInt(values[1].c_str());
                value._loop = tools::stringAsInt(values[2].c_str());
                oskill._action.push_back(value);
            }
        }
        {
            std::string str = skill->Attribute("buff");
            osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                osplitres values;
                tools::split(arrays[i], ",", values);
                oSkillBuff value;
                value._buff = tools::stringAsInt(values[0].c_str());
                value._type = tools::stringAsInt(values[1].c_str());
                oskill._buff.push_back(value);
            }
        }
        {
            std::string str = skill->Attribute("scene_effect");
            osplitres arrays;
            tools::split(str, ";", arrays);
            for (s32 i = 0; i < arrays.size(); i++) {
                int value = tools::stringAsInt(arrays[i].c_str());
                oskill._scene_effect.push_back(value);
            }
        }
        skill = skill->NextSiblingElement("skill");
        g_config_skill_map.insert(std::make_pair(oskill._id, oskill));
    }
}


struct o_config_task {
/*id*/
    int _id;
/*����
0.��ս
1.��ʤ
2.ι��
3.����
4.����*/
    int _type;
/*����*/
    string _dsc;
/*����*/
    int _count;
/*��ҽ���*/
    int _reward;
};
extern std::map<int, o_config_task> g_config_task_map;
inline void init_config_task(const std::string & path) {
    std::string xmlpath;
    xmlpath << path << "/" << "task.xml";
    TiXmlDocument config;
    if (!config.LoadFile(xmlpath.c_str())) {
        tassert(false, "load config %s error", xmlpath.c_str());
        return;
    }

    TiXmlElement * root = config.RootElement();
    TiXmlElement * task = root->FirstChildElement("task");
    while(task) {
        o_config_task otask;
        otask._id = tools::stringAsInt(task->Attribute("id"));
        otask._type = tools::stringAsInt(task->Attribute("type"));
        otask._dsc = task->Attribute("dsc");
        otask._count = tools::stringAsInt(task->Attribute("count"));
        otask._reward = tools::stringAsInt(task->Attribute("reward"));
        task = task->NextSiblingElement("task");
        g_config_task_map.insert(std::make_pair(otask._id, otask));
    }
}


#define config_init_macro     std::map<int, o_config_advertise> g_config_advertise_map; \
    std::map<int, o_config_buff> g_config_buff_map; \
    std::map<int, o_config_food> g_config_food_map; \
    o_global_config g_global_config; \
    std::map<int, o_config_level> g_config_level_map; \
    std::map<int, o_config_map> g_config_map_map; \
    std::map<int, o_config_match> g_config_match_map; \
    std::map<int, o_config_piece> g_config_piece_map; \
    std::map<int, o_config_random_shop> g_config_random_shop_map; \
    std::map<int, o_config_rank> g_config_rank_map; \
    std::map<int, o_config_resource> g_config_resource_map; \
    std::map<int, o_config_role> g_config_role_map; \
    std::map<int, o_config_rule> g_config_rule_map; \
    std::map<int, o_config_sceneeffect> g_config_sceneeffect_map; \
    std::map<int, o_config_skill> g_config_skill_map; \
    std::map<int, o_config_task> g_config_task_map; \


inline void initconfig(const std::string & path) {
    init_config_advertise(path);
    init_config_buff(path);
    init_config_food(path);
    init_global_config(path);
    init_config_level(path);
    init_config_map(path);
    init_config_match(path);
    init_config_piece(path);
    init_config_random_shop(path);
    init_config_rank(path);
    init_config_resource(path);
    init_config_role(path);
    init_config_rule(path);
    init_config_sceneeffect(path);
    init_config_skill(path);
    init_config_task(path);
}


class iConfig {
public:
    virtual ~iConfig() {}
    virtual const std::map<int, o_config_advertise> & get_advertise_config() = 0;
    virtual const std::map<int, o_config_buff> & get_buff_config() = 0;
    virtual const std::map<int, o_config_food> & get_food_config() = 0;
    virtual const o_global_config & get_global_config() = 0;
    virtual const std::map<int, o_config_level> & get_level_config() = 0;
    virtual const std::map<int, o_config_map> & get_map_config() = 0;
    virtual const std::map<int, o_config_match> & get_match_config() = 0;
    virtual const std::map<int, o_config_piece> & get_piece_config() = 0;
    virtual const std::map<int, o_config_random_shop> & get_random_shop_config() = 0;
    virtual const std::map<int, o_config_rank> & get_rank_config() = 0;
    virtual const std::map<int, o_config_resource> & get_resource_config() = 0;
    virtual const std::map<int, o_config_role> & get_role_config() = 0;
    virtual const std::map<int, o_config_rule> & get_rule_config() = 0;
    virtual const std::map<int, o_config_sceneeffect> & get_sceneeffect_config() = 0;
    virtual const std::map<int, o_config_skill> & get_skill_config() = 0;
    virtual const std::map<int, o_config_task> & get_task_config() = 0;
};


#define define_oconfig class OConfig : public iConfig { \
public: \
    virtual ~OConfig() {} \
    virtual const std::map<int, o_config_advertise> & get_advertise_config() { return g_config_advertise_map; } \
    virtual const std::map<int, o_config_buff> & get_buff_config() { return g_config_buff_map; } \
    virtual const std::map<int, o_config_food> & get_food_config() { return g_config_food_map; } \
    virtual const o_global_config & get_global_config() { return g_global_config; } \
    virtual const std::map<int, o_config_level> & get_level_config() { return g_config_level_map; } \
    virtual const std::map<int, o_config_map> & get_map_config() { return g_config_map_map; } \
    virtual const std::map<int, o_config_match> & get_match_config() { return g_config_match_map; } \
    virtual const std::map<int, o_config_piece> & get_piece_config() { return g_config_piece_map; } \
    virtual const std::map<int, o_config_random_shop> & get_random_shop_config() { return g_config_random_shop_map; } \
    virtual const std::map<int, o_config_rank> & get_rank_config() { return g_config_rank_map; } \
    virtual const std::map<int, o_config_resource> & get_resource_config() { return g_config_resource_map; } \
    virtual const std::map<int, o_config_role> & get_role_config() { return g_config_role_map; } \
    virtual const std::map<int, o_config_rule> & get_rule_config() { return g_config_rule_map; } \
    virtual const std::map<int, o_config_sceneeffect> & get_sceneeffect_config() { return g_config_sceneeffect_map; } \
    virtual const std::map<int, o_config_skill> & get_skill_config() { return g_config_skill_map; } \
    virtual const std::map<int, o_config_task> & get_task_config() { return g_config_task_map; } \
};

#endif //__auto_config_h__
