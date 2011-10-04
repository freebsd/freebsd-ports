# New ports collection makefile for:	roxterm
# Date created:		19 Jun 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	roxterm
PORTVERSION=	2.1.3
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.0 terminal emulator with tabs

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_XORG=	sm ice
USE_GNOME=	libglade2 vte
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_HAVE_XMLTO=no ac_cv_prog_HAVE_PO4A=no
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	roxterm.1 \
	roxterm-config.1

post-patch:
.for file in Makefile.in po4a/Makefile.in
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-data-local||g' \
		${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's/GtkBox/GtkVBox/g' \
		${WRKSRC}/src/roxterm-config.ui

post-install:
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/roxterm.svg \
		${PREFIX}/share/icons/hicolor/scalable/apps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS Changes README
	${INSTALL_DATA} ${WRKSRC}/Help/${file} ${DOCSDIR}
.endfor
.for dir in en lib
	@(cd ${WRKSRC}/Help && ${COPYTREE_SHARE} ${dir} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
