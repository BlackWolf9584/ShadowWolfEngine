using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Wolf;

namespace TestApp.src
{
    class PlayerCube : Entity
    {
        public float HorizontalForce = 10.0f;
        public float VerticalForce = 10.0f;

        private MaterialInstance m_MeshMaterial;

        void OnCreate()
        {
            MeshComponent meshComponent = GetComponent<MeshComponent>();
            m_MeshMaterial = meshComponent.Mesh.GetMaterial(0);
            m_MeshMaterial.Set("u_Metalness", 0.0f);
        }
        void OnUpdate(float ts)
        {
            Vector3 color = new Vector3(0.8f, 0.8f, 0.8f);
            if (Input.IsKeyPressed(KeyCode.Q))
                color = new Vector3(0.0f, 1.0f, 0.0f);

            m_MeshMaterial.Set("u_AlbedoColor", color);

            if (Input.IsKeyPressed(KeyCode.R))
            {
                Matrix4 transform = GetTransform();
                transform.Translation = new Vector3(0.0f);
                SetTransform(transform);
            }

        }

    }
}
