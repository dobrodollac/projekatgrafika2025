//#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    TexCoords = aTexCoords;
    gl_Position = projection * view * vec4(FragPos, 1.0);
}

//#shader fragment
#version 330 core

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

in vec3 Normal;
in vec3 FragPos;

struct DirLight {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform DirLight dirLight;
uniform vec3 viewPos;

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
uniform SpotLight spotLight;


void main()
{
    vec3 texColor = texture(texture_diffuse1, TexCoords).rgb;
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 lightDir = normalize(-dirLight.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);

    vec3 ambient  = dirLight.ambient  * texColor;
    vec3 diffuse  = dirLight.diffuse  * diff * texColor;
    vec3 specular = dirLight.specular * spec;

    vec3 result = ambient + diffuse + specular;

    vec3 lightDir2 = normalize(spotLight.position - FragPos);
    float theta = dot(normalize(lightDir2), normalize(-spotLight.direction));
    float epsilon = max(spotLight.cutOff - spotLight.outerCutOff, 0.001);
    float intensity = clamp((theta - spotLight.outerCutOff) / epsilon, 0.0, 1.0);
    intensity *= 10.0;


    float diff2 = max(dot(norm, lightDir2), 0.0);
    vec3 reflectDir2 = reflect(-lightDir2, norm);
    float spec2 = pow(max(dot(viewDir, reflectDir2), 0.0), 32.0);

    float distance = length(spotLight.position - FragPos);
    float attenuation = 1.0 / (spotLight.constant + spotLight.linear * distance +
                               spotLight.quadratic * distance * distance);

    vec3 ambient2  = spotLight.ambient  * texColor;
    vec3 diffuse2  = spotLight.diffuse  * diff2 * texColor;
    vec3 specular2 = spotLight.specular * spec2;

    vec3 spotResult = (ambient2 + (diffuse2 + specular2) * intensity) * attenuation;

    vec3 finalColor = result + spotResult;
    FragColor = vec4(finalColor, 1.0);
}