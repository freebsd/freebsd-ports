# New ports collection makefile for:	kdebase2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION= 	1.94
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/distribution/2.0Beta5/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22 \
		kdeui.4:${PORTSDIR}/x11/kdelibs2 \
		intl.1:${PORTSDIR}/devel/gettext

SOMAJOR=	4
SOMINOR=	0
MOC?=		${X11BASE}/bin/moc2
USE_XPM=	yes
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-xdmdir=${X11BASE}/lib/X11/xdm \
		--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib \
		--disable-closure
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lstdc++ -lgcc"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/libkonq/Makefile.in
	${PERL} -pi -e "s@version-info 1:0:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/khelpcenter/Makefile.in
	${PERL} -pi -e "s@version-info 1:1:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/nsplugins/Makefile.in

.include <bsd.port.mk>
