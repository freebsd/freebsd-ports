PORTNAME=	labltk
PORTVERSION=	8.06.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://download.ocamlcore.org/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Objective Caml interface to Tk

LICENSE=	LGPL20

USES=		gmake tk
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-tkdefs "-I${LOCALBASE}/include -I${TCL_INCLUDEDIR}\
		-I${TK_INCLUDEDIR}" \
		-tklibs "-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}\
		-ltk${TK_SHLIB_VER}" -verbose
MAKE_JOBS_UNSAFE=yes
USE_OCAML=	yes

ALL_TARGET=	all opt

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} \
		-e 's/$$(INSTALLDIR)/$$(DESTDIR)$$(INSTALLDIR)/g' \
		-e 's/$$(INSTALLBINDIR)/$$(DESTDIR)$$(INSTALLBINDIR)/g' \
		-e 's/$$(STUBLIBDIR)/$$(DESTDIR)$$(STUBLIBDIR)/g' \
		-e 's/mkdir /& -p /g'

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs

post-install:
	${INSTALL_DATA} ${WRKSRC}/support/META ${STAGEDIR}${PREFIX}/lib/ocaml/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs/dlllabltk.so

.include <bsd.port.mk>
