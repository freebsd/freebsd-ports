# Created by: Michael Grünewald <michipili@gmail.com>
# $FreeBSD$

PORTNAME=	labltk
PORTVERSION=	8.06.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1455/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Objective Caml interface to Tk

LICENSE=	LGPL20

USES=		gmake tk
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
MAKE_ENV+=	STAGEDIR="${STAGEDIR}"
USE_OCAML=	yes

ALL_TARGET=	all opt

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} \
		-e 's/$$(INSTALLDIR)/$$(STAGEDIR)$$(INSTALLDIR)/g' \
		-e 's/$$(INSTALLBINDIR)/$$(STAGEDIR)$$(INSTALLBINDIR)/g' \
		-e 's/$$(STUBLIBDIR)/$$(STAGEDIR)$$(STUBLIBDIR)/g' \
		-e 's/mkdir /& -p /g'
	@${REINPLACE_CMD} -e 's|%%SCRIPTBASE%%|${PREFIX}/lib/ocaml/labltk/|g' \
		${WRKSRC}/lib/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs

post-install:
	${INSTALL_DATA} ${WRKSRC}/support/META ${STAGEDIR}${PREFIX}/lib/ocaml/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs/dlllabltk.so

.include <bsd.port.mk>
