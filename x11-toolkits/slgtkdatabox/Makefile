# New ports collection makefile for:	slgtkdatabox
# Date created:		15 Aug 2008
# Whom:			Alexey Shuvaev <shuvaev@phyisik.uni-wuerzburg.de>
#
# $FreeBSD$
#

PORTNAME=	slgtkdatabox
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://laurent.perez2.free.fr/comp/slang/modules/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	S-Lang binding for gtkdatabox

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2 \
		gtkdatabox-0.9.0.1:${PORTSDIR}/x11-toolkits/gtkdatabox
RUN_DEPENDS=	imdisplay:${PORTSDIR}/x11-toolkits/slgtk

OPTIONS=	SLGLADE	"Enable slglade support (run-time)" off

.include <bsd.port.pre.mk>

.if defined(WITH_SLGLADE)
RUN_DEPENDS+=	${LOCALBASE}share/slsh/local-packages/glade.sl:${PORTSDIR}/devel/slglade
PLIST_SUB+=	SLGLADE=""
.else
PLIST_SUB+=	SLGLADE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl//' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/gtkdatabox-module.so \
		${PREFIX}/lib/slang/v2/modules
	${INSTALL_DATA} ${WRKSRC}/gtkdatabox.sl \
		${PREFIX}/share/slsh/local-packages
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/??[a-mo-z]*.sl ${EXAMPLESDIR}
.if defined(WITH_SLGLADE)
	${INSTALL_DATA} ${WRKSRC}/examples/line_attributes.glade ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/line_attributes.sl ${EXAMPLESDIR}
.endif
.endif

.include <bsd.port.post.mk>
