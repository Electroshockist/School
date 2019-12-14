using System;
using UnityEngine;
using UnityEngine.Rendering.PostProcessing;

[Serializable, PostProcess(typeof(HSCIRenderer), PostProcessEvent.AfterStack, "Custom/HSCI", true)]
public sealed class HSCI : PostProcessEffectSettings
{
    public FloatParameter power = new FloatParameter() { value = 0 };
   
}

public sealed class HSCIRenderer : PostProcessEffectRenderer<HSCI>
{
    public override void Render(PostProcessRenderContext context)
    {
        var sheet = context.propertySheets.Get(Shader.Find("Hidden/HSCI"));
        sheet.properties.SetFloat("_Power", settings.power);
        context.command.BlitFullscreenTriangle(context.source, context.destination, sheet, 0);
    }
}
