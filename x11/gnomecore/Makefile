# New ports collection makefile for:	gnomecore
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomecore
PORTVERSION=	1.4.2
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-core/1.4
DISTNAME=	gnome-core-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier libcapplet libglade gnomeaudio \
		libpanel
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		deskguide_applet.1 gmenu.1 gnome-about.1 gnome-convert.1 \
		gnome-download.1 gnome-edit.1 gnome-hint-properties-capplet.1 \
		gnome-hint.1 gnome-info2html.1 gnome-man2html.1 \
		gnome-panel-add-launcher.1 gnome-panel-properties-capplet.1 \
		gnome-session.1 gnome-terminal.1 gnome-wm.1 panel.1 \
		save-session.1 tasklist_applet.1 gnome-libice-check.1 \
		gnome-login-check.1 gnome-smproxy.1 session-properties.1 \
		session-properties-capplet.1 
MAN5=		default.session.5

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
