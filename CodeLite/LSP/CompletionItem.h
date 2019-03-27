#ifndef COMPLETIONITEM_H
#define COMPLETIONITEM_H

#include "LSP/JSONObject.h"
#include <vector>
#include <wx/sharedptr.h>
#include "LSP/basic_types.h"

namespace LSP
{
class WXDLLIMPEXP_CL CompletionItem : public Serializable
{
    wxString m_label;
    int m_kind = wxNOT_FOUND;
    wxString m_detail;
    wxString m_documentation;
    wxString m_filterText;
    wxString m_insertText;
    LSP::TextEdit m_textEdit;

public:
    enum eTriggerKind {
        kTriggerUnknown = -1,
        kTriggerKindInvoked = 1,              // Completion was triggered by typing an identifier (24x7 code complete)
        kTriggerCharacter = 2,                // Completion was triggered by a trigger character (e.g. ".")
        kTriggerForIncompleteCompletions = 3, // user internally
        kTriggerUser = 4,                     // manual invocation (e.g Ctrl+Space)
    };

    enum eCompletionItemKind {
        kKindText = 1,
        kKindMethod = 2,
        kKindFunction = 3,
        kKindConstructor = 4,
        kKindField = 5,
        kKindVariable = 6,
        kKindClass = 7,
        kKindInterface = 8,
        kKindModule = 9,
        kKindProperty = 10,
        kKindUnit = 11,
        kKindValue = 12,
        kKindEnum = 13,
        kKindKeyword = 14,
        kKindSnippet = 15,
        kKindColor = 16,
        kKindFile = 17,
        kKindReference = 18,
        kKindFolder = 19,
        kKindEnumMember = 20,
        kKindConstant = 21,
        kKindStruct = 22,
        kKindEvent = 23,
        kKindOperator = 24,
        kKindTypeParameter = 25,
    };

public:
    typedef wxSharedPtr<CompletionItem> Ptr_t;
    typedef std::vector<CompletionItem::Ptr_t> Vec_t;

public:
    CompletionItem();
    virtual ~CompletionItem();
    virtual JSONItem ToJSON(const wxString& name) const;
    virtual void FromJSON(const JSONItem& json);
    void SetDetail(const wxString& detail) { this->m_detail = detail; }
    void SetDocumentation(const wxString& documentation) { this->m_documentation = documentation; }
    void SetFilterText(const wxString& filterText) { this->m_filterText = filterText; }
    void SetInsertText(const wxString& insertText) { this->m_insertText = insertText; }
    void SetKind(int kind) { this->m_kind = kind; }
    void SetLabel(const wxString& label) { this->m_label = label; }
    const wxString& GetDetail() const { return m_detail; }
    const wxString& GetDocumentation() const { return m_documentation; }
    const wxString& GetFilterText() const { return m_filterText; }
    const wxString& GetInsertText() const { return m_insertText; }
    int GetKind() const { return m_kind; }
    const wxString& GetLabel() const { return m_label; }
    void SetTextEdit(const LSP::TextEdit& textEdit) { this->m_textEdit = textEdit; }
    const LSP::TextEdit& GetTextEdit() const { return m_textEdit; }
};

}; // namespace LSP

#endif // COMPLETIONITEM_H