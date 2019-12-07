using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace MapEditor
{
    
    class CObject
    {
        
        private int id;
        public Rectangle region;
       
        public int idName;
        public int multiFunc;
        public string ReverseLo_Start;
        public string ReverseLo_End;
        public int ID { get => id; }
        public int width, height;

        public CObject(int id, Rectangle region, string idName, string MultiFunc, string ReverseLo_Start, string ReverseLo_End)
        {
            this.id = id;
            this.region = region;
            switch(idName)
            {
               
                case "BRICK":
                    this.idName = (int)eType.BRICK;
                    this.height = 5;
                    break;
                case "ARROW":
                    this.idName = (int)eType.ARROW;
                    this.width = 51;
                    this.height = 35;
                    break;
                case "BOB":
                    this.idName = (int)eType.BOB;
                    this.width = 33;
                    this.height = 67;
                    break;
                case "MOVINGBRICK":
                    this.idName = (int)eType.MOVINGBRICK;
                    this.width = 42;
                    this.height = 24;
                    break;
                case "WALL":
                    this.idName = (int)eType.WALL;
                    this.width = 5;
                    break;
                case "ROPE":
                    this.idName = (int)eType.ROPE;
                    this.width = 1;
                    break;
                case "APPLE":
                    this.idName = (int)eType.APPLE;
                    this.width = 11;
                    this.height = 12;
                    break;
                case "REDJEWEL":
                    this.idName = (int)eType.REDJEWEL;
                    this.width = 17;
                    this.height = 16;
                    break;
                case "GENIE":
                    this.idName = (int)eType.GENIE;
                    this.width = 38;
                    this.height = 50;
                    break;
                case "HEART":
                    this.idName = (int)eType.HEART;
                    this.width = 19;
                    this.height = 23;
                    break;
                case "RESTARTPOINT":
                    this.idName = (int)eType.RESTARTPOINT;
                    this.width = 20;
                    this.height = 33;
                    break;

            }
            switch(MultiFunc)
            {
                case "RIGHT":
                    this.multiFunc = 1;
                    break;
                case "LEFT":
                    this.multiFunc = -1;
                    break;
                case "come in":
                    this.multiFunc = 1;
                    break;
                case "come out":
                    this.multiFunc = 0;
                    break;

            }
            this.ReverseLo_Start = ReverseLo_Start;
            this.ReverseLo_End = ReverseLo_End;
        }
        public string Output()
        {
            string output;
            switch (idName)
            {
                case 20:
                    width = region.Width;
                    break;
                case 26:
                    height = region.Height;
                    break;
                case 24:
                    height = region.Height;
                    break;
            }
            output = idName.ToString() +" 0 "+width+" " +height+" " + region.X.ToString() + " " + region.Y.ToString()+ " " + multiFunc.ToString();
            return output;
        }
    }
    enum eType
    {
        NINJA = 01,
        NINJA_TRANS = 02,
        NINJA_DEADTH = 03,

        // object nền(Bat Dau 20)
        BRICK = 20,
        ARROW=21,
        BOB=22,
        MOVINGBRICK=23,
        WALL=24,
        ROPE=26,
        APPLE=27,
        REDJEWEL=28,
        GENIE=29,
        HEART=30,
        RESTARTPOINT=31,

        // object(Bat Dau 40)

        // other (Bat Dau 100)
        Map1 = 100,
        Map2 = 101,
        Map3 = 102,
        BBOX = 103,



        // Enemy(Bat Dau 120)
      
    };
}
