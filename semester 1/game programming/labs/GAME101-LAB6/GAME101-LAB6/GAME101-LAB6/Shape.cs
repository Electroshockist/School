using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GAME101_LAB6
{
    public abstract class Shape
    {
        protected string name;
        protected string color;
        protected string shapeType;

        public Shape(string n, string c)
        {
            name = n;
            color = c;
        }

        public abstract string getShapeType();

        public abstract double area();

        public string getName()
        {
            return name;
        }

        public string getColor()
        {
            return color;
        }
    }
}
