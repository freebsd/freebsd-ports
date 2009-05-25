# New ports collection makefile for:	wmfs
# Date created:		08 December 2008
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	wmfs
DISTVERSION=	0.1rc4
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://wmfs.info/files/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A floating and tiling Window Manager From Scratch

BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2 \
		confuse.0:${PORTSDIR}/devel/libconfuse

USE_GNOME=	pkgconfig
USE_CMAKE=	yes
USE_XORG=	x11 xft xpm

MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/wmfs \
		etc/xdg/wmfs/wmfsrc \
		%%DOCSDIR%%/TODO \
		%%DOCSDIR%%/README \
		%%DOCSDIR%%/CHANGELOG \
		%%DOCSDIR%%/wmfsrc
PLIST_DIRS=	%%DOCSDIR%% etc/xdg/wmfs etc/xdg

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/$${PROJECT_NAME})|${DOCSDIR})|g' \
		-e 's|$${PREFIX}/share/man|/$${PREFIX}/man|g' \
		-e 's|$${SYSCONFDIR}/xdg|${PREFIX}/etc/xdg|g'  ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfs ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/TODO
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}/CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/wmfsrc ${DOCSDIR}/wmfsrc
.endif

	@${CAT} ${PKGMESSAGE} | ${SED} "s|PREFIX|${PREFIX}|g" \
		${PKGDIR}/pkg-message

.include <bsd.port.post.mk>
